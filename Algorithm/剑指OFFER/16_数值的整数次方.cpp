//
//  16_数值的整数次方.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//
//复杂度log(n)
#include <stdio.h>
double powhelp(double x, int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    int p = powhelp(x, n/2);
    if(n % 2 == 0)
        return p * p;
    else
        return p * p * x;
}

double Power(double base, int exponent) {
    if(exponent == 0) return 1.0;
    if(base == 1 || base == 0) return base;
    if(exponent < 0){
       return (1 / powhelp(base, -exponent));
    }
    else
        return powhelp(base, exponent);
}
