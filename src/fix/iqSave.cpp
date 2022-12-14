//
// Created by jcc on 22-12-12.
//

#include "fix/iqSave.h"
#include "cmath"

iqSave::iqSave(const string& file) {
    _iqFile.open(file);
    _saveSize = 0;
}

iqSave::~iqSave() {
    _iqFile.close();
}

void iqSave::save_iq_data(int16_t *iq_data, int16_t samples) {
    if(_saveSize >= 1000)
        return;
    for(int i=0;i<samples;i++){
//        int16_t data = ((iq_data[i*2] * iq_data[i*2] + iq_data[i*2+1]*iq_data[i*2+1]));
        _iqFile << iq_data[i] << " ";
    }
    _saveSize++;
}
