//
//  3_数组中重复的数字.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
//把数字移到对应的位置，若有重复则是重复数字
bool duplicate(int numbers[], int length, int* duplication) {
    if(numbers == NULL || length <=0) return false;
    for(int i = 0; i < length; i++){
        while(numbers[i] != i){
            if(numbers[i] == numbers[numbers[i]]){
                duplication[0] = numbers[i];
                return true;
            }
            swap(numbers[i], numbers[numbers[i]]);
        }
    }
    return false;
}
