//
//  42_最大连续子数组和.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/7.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxSum(vector<int> v){
    int N = (int)v.size(), count = 0, res = INT_MIN;
    for (int i = 0; i < N; i++) {
        if(count <= 0){
            count = v[i];
        }
        count += v[i];
        res = max(res, count);
    }
    return res;
}
int main(){
    vector<int> v = {6, -3, -2, 7, -15, 1, 2, 2};
    cout<<maxSum(v)<<endl;
}
