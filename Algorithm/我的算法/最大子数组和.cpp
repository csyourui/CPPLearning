//
//  最大子数组和.cpp
//  test
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//3 -1 4 2 1 -4 3 -2 1 5
int MSA(vector<int> v){
    int N = (int)v.size(), count = 0, res = INT_MIN;
    for (int i = 0; i < N; i++) {
        if(count < 0)
            count = v[i];
        else
            count += v[i];
        res = max(res, count);
    }
    return res;
}

int main(){
    vector<int> v = {-1,-2,-5};
    cout<<MSA(v)<<endl;
}
