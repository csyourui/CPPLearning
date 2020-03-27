//
//  4_二维数组的查找.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
//数组是有序的可以从左下角开始查找 O(m+n)
bool Find(int target, vector<vector<int> > array) {
    int m = array.size(), n = array[0].size();
    int i = m-1, j = 0;
    while(i>=0&&j<=n-1){
        if(array[i][j] == target)
            return true;
        if(array[i][j] > target)
            i--;
        else
            j++;
    }
    return false;
}
