//
// Created by jcc on 22-12-12.
//

#ifndef SPECTRUM_IQSAVE_H
#define SPECTRUM_IQSAVE_H
#include "fstream"
#include "iostream"

using namespace std;

class iqSave{
public:
    explicit iqSave(const string& file="iqdata.txt");
    ~iqSave();

    void save_iq_data(int16_t *iq_data, int16_t samples);

public:
    std::ofstream _iqFile;
    int _saveSize;
};

#endif //SPECTRUM_IQSAVE_H
