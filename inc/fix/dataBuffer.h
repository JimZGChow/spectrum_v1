//
// Created by jcc on 22-11-28.
//

#ifndef SPECTRUM_DATABUFFER_H
#define SPECTRUM_DATABUFFER_H

#include "cstdint"
#include "cstring"

/*
 *	a simple ringbuffer, lockfree, however only for a
 *	single reader and a single writer.
 *	Mostly used for getting samples from or to the soundcard
 */
#if defined(__APPLE__)
#   include <libkern/OSAtomic.h>
    /* Here are the memory barrier functions. Mac OS X only provides
       full memory barriers, so the three types of barriers are the same,
       however, these barriers are superior to compiler-based ones. */
#   define PaUtil_FullMemoryBarrier()  OSMemoryBarrier()
#   define PaUtil_ReadMemoryBarrier()  OSMemoryBarrier()
#   define PaUtil_WriteMemoryBarrier() OSMemoryBarrier()
#elif defined(__GNUC__)
/* GCC >= 4.1 has built-in intrinsics. We'll use those */
#   if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
# define PaUtil_FullMemoryBarrier()  __sync_synchronize()
# define PaUtil_ReadMemoryBarrier()  __sync_synchronize()
# define PaUtil_WriteMemoryBarrier() __sync_synchronize()
/* as a fallback, GCC understands volatile asm and "memory" to mean it
 * should not reorder memory read/writes */
#   elif defined( __PPC__ )
#      define PaUtil_FullMemoryBarrier()  asm volatile("sync":::"memory")
#      define PaUtil_ReadMemoryBarrier()  asm volatile("sync":::"memory")
#      define PaUtil_WriteMemoryBarrier() asm volatile("sync":::"memory")
#   elif defined( __i386__ ) || defined( __i486__ ) || defined( __i586__ ) || defined( __i686__ ) || defined( __x86_64__ )
#      define PaUtil_FullMemoryBarrier()  asm volatile("mfence":::"memory")
#      define PaUtil_ReadMemoryBarrier()  asm volatile("lfence":::"memory")
#      define PaUtil_WriteMemoryBarrier() asm volatile("sfence":::"memory")
#   else
#      ifdef ALLOW_SMP_DANGERS
#         warning Memory barriers not defined on this system or system unknown
#         warning For SMP safety, you should fix this.
#         define PaUtil_FullMemoryBarrier()
#         define PaUtil_ReadMemoryBarrier()
#         define PaUtil_WriteMemoryBarrier()
#      else
#         error Memory barriers are not defined on this system. You can still compile by defining ALLOW_SMP_DANGERS, but SMP safety will not be guaranteed.
#      endif
#   endif
#else
#   ifdef ALLOW_SMP_DANGERS
#      warning Memory barriers not defined on this system or system unknown
#      warning For SMP safety, you should fix this.
#      define PaUtil_FullMemoryBarrier()
#      define PaUtil_ReadMemoryBarrier()
#      define PaUtil_WriteMemoryBarrier()
#   else
#      error Memory barriers are not defined on this system. You can still compile by defining ALLOW_SMP_DANGERS, but SMP safety will not be guaranteed.
#   endif
#endif

template <class elementType>
class DataBuffer{
private:
    uint32_t _buffer_size;

    volatile uint32_t _write_index;
    volatile uint32_t _read_index;

    uint32_t _small_mask;
    uint32_t _big_mask;
    char *_buffer;

public:
    explicit DataBuffer(uint32_t elementCount = 2*16384){
//        if(((elementCount - 1) & elementCount) != 0 )
//            elementCount = 2 *16384; /* default */

        _buffer_size = elementCount * 2; /* iq size */
        _buffer = new char[2 * _buffer_size * sizeof(elementType)];
        _write_index = 0;
        _read_index = 0;
        _small_mask = elementCount - 1;
        _big_mask = elementCount * 2 - 1;
    }

    ~DataBuffer(){
        delete[] _buffer;
    }


    uint32_t get_data_buffer_read_available(){
        return (_write_index - _read_index) & _big_mask;
    }

    uint32_t get_data_buffer_write_available(){
        return _buffer_size - get_data_buffer_read_available();
    }

    uint32_t write_space() {
        return get_data_buffer_write_available();
    }

    void flash_data_buffer(){
        _write_index = 0;
        _read_index = 0;
    }

    uint32_t advance_data_buffer_writeindex(uint32_t element_count){
        PaUtil_WriteMemoryBarrier();
        return _write_index = (_write_index + element_count);
    }

    uint32_t advance_data_buffer_readindex(uint32_t element_count){
        PaUtil_ReadMemoryBarrier();
        return _read_index = (_read_index + element_count);
    }

    uint32_t get_data_buffer_write_regions(uint32_t element_count,
                                           void **data_ptr1,uint32_t *size_ptr1,
                                           void **data_ptr2,uint32_t *size_ptr2){
        uint32_t index;
        uint32_t available = this -> get_data_buffer_write_available();

        if(element_count > available)
            element_count = available;

        index = _write_index & _small_mask;

        if((index  + element_count) > _buffer_size){
            uint32_t first_half = _buffer_size - index;
            *data_ptr1 = &_buffer[index * sizeof(elementType)];
            *size_ptr1 = first_half;
            *data_ptr2 = &_buffer[0];
            *size_ptr2 = element_count - first_half;
        }else{
            *data_ptr1 = &_buffer[index * sizeof(elementType)];
            *size_ptr1 = element_count;
            *data_ptr2 = nullptr;
            *size_ptr2 = 0;
        }

        if(available > 0)
            PaUtil_FullMemoryBarrier();

        return element_count;

    }


    uint32_t get_data_buffer_read_regions(uint32_t element_count,
                                           void **data_ptr1,uint32_t *size_ptr1,
                                           void **data_ptr2,uint32_t *size_ptr2){
        uint32_t index;
        uint32_t available = this -> get_data_buffer_read_available();

        if(element_count > available)
            element_count = available;

        index = _read_index & _small_mask;
        if((index + element_count) > _buffer_size){
            uint32_t first_half = _buffer_size - index;
            *data_ptr1 = &_buffer[index * sizeof(elementType)];
            *size_ptr1 = first_half;
            *data_ptr2 = &_buffer[0];
            *size_ptr2 = element_count - first_half;
        }
        else{
            *data_ptr1 = &_buffer[index * sizeof(elementType)];
            *size_ptr1 = element_count;
            *data_ptr2 = nullptr;
            *size_ptr2 = 0;
        }
        if(available)
            PaUtil_ReadMemoryBarrier();

        return element_count;
    }

    uint32_t put_data_into_buffer(const void *data,uint32_t element_count){
        uint32_t size_1,size_2,num_writeen;
        void *data1;
        void *data2;

        num_writeen = get_data_buffer_write_regions(element_count,
                                                      &data1,&size_1,
                                                      &data2,&size_2);

        if(size_2 > 0){
            memcpy(data1,data,size_1*sizeof(elementType));
            data = ((char *)data) + size_1 * sizeof(elementType);
            memcpy(data2,data,size_2 * sizeof(elementType));
        }else{
            memcpy(data1,data,size_1 * sizeof(elementType));
        }
        this ->advance_data_buffer_writeindex(num_writeen);
        return num_writeen;
    }

    uint32_t get_data_from_buffer(void *data,uint32_t element_cout){
        uint32_t size_1,size_2,num_read;
        void *data_1;
        void *data_2;

        num_read = get_data_buffer_read_regions(element_cout,
                                                &data_1,&size_1,
                                                &data_2,&size_2);

        if(size_2 > 0){
            memcpy(data,data_1,size_1 * sizeof(elementType));
            data = ((char *)data) + size_1 *sizeof(elementType);
            memcpy(data,data_2,size_2 * sizeof(elementType));
        } else{
            memcpy(data,data_1,size_1 * sizeof(elementType));
        }

        advance_data_buffer_readindex(num_read);
        return num_read;
    }

    uint32_t skip_data_in_buffer(uint32_t n_values){
        PaUtil_FullMemoryBarrier();
        if(n_values > get_data_buffer_read_available())
            n_values = get_data_buffer_read_available();

        advance_data_buffer_readindex(n_values);
        return n_values;
    }

};
#endif //SPECTRUM_DATABUFFER_H






























