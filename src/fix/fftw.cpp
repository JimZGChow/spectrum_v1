//
// Created by jcc on 22-11-28.
//
#include "fix/fftw_common.h"


common_fft::common_fft(int32_t size) {
    this -> _fft_size = size;

    _vector = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * size);

    _plan = fftw_plan_dft_1d(size,reinterpret_cast<fftw_complex*>(_vector),
                             reinterpret_cast<fftw_complex*>(_vector),
                             FFTW_FORWARD,FFTW_ESTIMATE);
}

common_fft::~common_fft() {
    if(_vector)
        fftw_free(_vector);
    if(_plan)
        fftw_destroy_plan(_plan);
}

fftw_complex *common_fft::getVector(void) {
    return _vector;
}

void common_fft::do_FFT(void) {
    fftw_execute(_plan);
}

void common_fft::do_Shift(void) {
    auto *v = (fftw_complex *) fftw_malloc(this->_fft_size * sizeof(fftw_complex));

    memcpy(v,_vector,_fft_size * sizeof(fftw_complex));
    memcpy(_vector,&v[this -> _fft_size  /2],this -> _fft_size / 2 * sizeof(fftw_complex));
    memcpy(&_vector[this -> _fft_size / 2], v , this -> _fft_size  / 2 * sizeof(fftw_complex));
}

fftw_complex *common_fft::resetVecotr(int32_t size) {
    if(_vector)
        fftw_free(_vector);

    _vector = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * size);
    return _vector;
}

