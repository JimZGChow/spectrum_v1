//
// Created by jcc on 22-11-30.
//

#ifndef SPECTRUM_MY_MATH_H
#define SPECTRUM_MY_MATH_H

#include <cmath>


int get_one_number_from_position(double input,int index){
    return index == 9 ? (int)((long long int)input / (long long int)(pow(10,index))):
                   (int)(((long long int)input % (long long int)(pow(10,index+1))) / (long long int) pow(10,index));
}




#endif //SPECTRUM_MY_MATH_H
