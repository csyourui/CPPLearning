//
//  11_旋转数字的最小数字.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
//二分查找复杂度O(logN)
int minNumberInRotateArray(vector<int> rotateArray) {
    int low = 0, high = rotateArray.size()-1;
    while(low < high){
        int mid = low + (high - low)/2;
        if(rotateArray[mid] > rotateArray[high])
            low = mid+1;
        else
            high = mid;
    }
    return rotateArray[low];
}
