//
//  11_旋转数字的最小数字.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
//二分查找复杂度O(logN)
int minNumberInRotateArray(vector<int> numbers) {
    int l = 0, r = numbers.size() - 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        //如果中间比右边要小，右边一定为升序
        if(numbers[mid] < numbers[r]){
            r = mid;
        }else if(numbers[mid] > numbers[r]){
            l = mid + 1;
        }else r--;
    }
    return numbers[l];
}
