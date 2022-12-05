//
// Created by jcc on 22-12-3.
//

#include "fix/my_math.h"

int get_one_number_from_position(double input,int index){
    return index == 9 ? (int)((long long int)input / (long long int)(pow(10,index))):
           (int)(((long long int)input % (long long int)(pow(10,index+1))) / (long long int) pow(10,index));
}

void fft_data_average(QVector<double>& src_data,int average_point,int all_sample_size){
    if(average_point == 1){
        return;
    }

    for(int i = 0;i < src_data.size();i++){
        int index = i - average_point / 2 ;
        int index_end = index + average_point;
        double temp = 0.f;
        int cnt = 0;
        for(;index < index_end;index++){
            if(index >= 0 && index < all_sample_size){
                cnt++;
                temp += src_data[index];
            }
        }
        src_data[i] = temp / cnt;
    }
}

float set_window(int16_t i, int size, int index, int window_type) {
    if (window_type == 0){
        return (float)i * (0.54f - 0.46f * cosf(2.0f * M_PI * index / (size - 1)));
    }
    else if(window_type == 1){
        return (float)i * (1.0f - cosf(2.0f * M_PI * (float)index / (size - 1)));
    }
    else if(window_type == 2){
        return (float)i * (0.42f - 0.5f * cosf(2.0f * (float)index * M_PI / ((float)size-1.0f) + 0.08f * cosf(4.0f*(float)index*M_PI / ((float)size-1.0f))));
    }
    else {
        return i;
    }
}

void get_window_coefficient(float *coefficient,int size,int window_type){
    if(window_type == 0){
        for(int i=0;i<size;i++){
            coefficient[i] = (0.54f - 0.46f * cosf(2.0f * M_PI * i / (size - 1)));
        }
    }
    else if(window_type == 1){
        for(int i=0;i<size;i++){
            coefficient[i] = (1.0f - cosf(2.0f * M_PI * (float)i / (size - 1)));
        }
    }
    else if(window_type == 2){
        for(int i=0;i<size;i++){
            coefficient[i] = (0.42f - 0.5f * cosf(2.0f * (float)i * M_PI / ((float)size-1.0f) + 0.08f * cosf(4.0f*(float)i*M_PI / ((float)size-1.0f))));
        }
    }
    else {
        for(int i=0;i<size;i++){
            coefficient[i] = 1;
        }
    }

}
