//
//  15_二进制1的个数.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 
 n       : 10110100
 n-1     : 10110011
 n&(n-1) : 10110000
 
 */
#include <stdio.h>
int NumberOf1(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n &= (n - 1);
    }
    return count;
}
