//
//  21_调整数组顺序使奇数位于偶数前面.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//
//相对位置要求不变
#include <stdio.h>
void reOrderArray(vector<int> &array) {
    //1,2,3,4,5
    //1,3,5,2,4
    int N = array.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N-i-1;j++){
            if(array[j]%2==0 && array[j+1]%2!=0){
                swap(array[j], array[j+1]);
            }
        }
    }
}
