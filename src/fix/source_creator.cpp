//
// Created by jcc on 22-12-1.
//
#include "fix/source_creator.h"
#include "iostream"

SINCOS::SINCOS(std::string type, double fs, uint32_t sample_count, double frequency) {
    this->_type = std::move(type);
    this->_fs = fs;
    this->_sample_count = sample_count;
    this->_frequency = frequency;

    _data_source = (DSPCOMPLEX*) fftwf_malloc( sizeof(DSPCOMPLEX) * _sample_count);

    if(this->_type == "SIN"){
        for(uint32_t i = 0;i <= _sample_count ;i++){
            _data_source[i][0] = sin(2 * M_PI * _frequency * (1. / _fs) * i);
            _data_source[i][1] = 0;
        }
    }
    else{
        for(uint32_t i = 0;i < _sample_count ;i++){
            _data_source[i][0] = cos(2 * M_PI * _frequency * (1. / _fs) * i);
            _data_source[i][1] = 0;
        }
    }

}

SINCOS::~SINCOS() {
    delete _data_source;
}

void SINCOS::save_source_file(std::string path) {
    _saveFile.open(path,std::ios::out);
    for(uint32_t i = 0;i < _sample_count ;i++){
        _saveFile << _data_source[i][0] << std::endl;
    }
    _saveFile.close();
}
