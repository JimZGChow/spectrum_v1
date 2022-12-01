//
// Created by jcc on 22-12-1.
//

#ifndef SPECTRUM_SOURCE_CREATOR_H
#define SPECTRUM_SOURCE_CREATOR_H

#include <utility>

#include "cmath"
#include "string"
#include "fftw_common.h"
#include "fstream"

using namespace std;
class SINCOS{
public:
    explicit SINCOS(std::string type = "COS",
                    double fs = 1e6,
                    uint32_t sample_count = 1024,
                    double frequency = 10e3);
    ~SINCOS();

    DSPCOMPLEX* get_source_ptr(){
        return this->_data_source;
    }

    uint32_t get_source_size(){
        return this->_sample_count;
    }

    void save_source_file(std::string path);
private:
    string _type;
    double _fs;
    uint32_t _sample_count;
    double _frequency;
    DSPCOMPLEX *_data_source;
    std::ofstream _saveFile;
};



#endif //SPECTRUM_SOURCE_CREATOR_H
