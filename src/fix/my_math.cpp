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