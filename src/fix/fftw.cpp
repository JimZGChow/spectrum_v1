//
// Created by jcc on 22-11-28.
//
#include "fix/fftw_common.h"


common_fft::common_fft(int32_t size) {
    this -> _fft_size = size;

    _vector = (DSPCOMPLEX *) fftwf_malloc(sizeof(DSPCOMPLEX) * size);

    _plan = fftwf_plan_dft_1d(size,reinterpret_cast<DSPCOMPLEX*>(_vector),
                             reinterpret_cast<DSPCOMPLEX*>(_vector),
                             FFTW_FORWARD,FFTW_ESTIMATE);
}

common_fft::~common_fft() {
    if(_vector)
        fftwf_free(_vector);
    if(_plan)
        fftwf_destroy_plan(_plan);
}

DSPCOMPLEX *common_fft::getVector(void) {
    return _vector;
}

void common_fft::do_FFT(void) {
    fftwf_execute(_plan);
}

void common_fft::do_Shift(void) {
    auto *v = (fftw_complex *) fftwf_malloc(this->_fft_size * sizeof(fftw_complex));

    memcpy(v,_vector,_fft_size * sizeof(fftw_complex));
    memcpy(_vector,&v[this -> _fft_size  /2],this -> _fft_size / 2 * sizeof(fftw_complex));
    memcpy(&_vector[this -> _fft_size / 2], v , this -> _fft_size  / 2 * sizeof(fftw_complex));
}

DSPCOMPLEX *common_fft::resetVecotr(int32_t size) {
    if(_vector)
        fftwf_free(_vector);

    _vector = (DSPCOMPLEX *) fftwf_malloc(sizeof(DSPCOMPLEX) * size);
    return _vector;
}

