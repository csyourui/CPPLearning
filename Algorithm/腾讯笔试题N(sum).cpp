//
//  腾讯笔试题N(sum).cpp
//  C++Learning
//
//  Created by yourui on 2020/4/16.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
 写一个函数 void foo(arr, m, n)，arr是整数数组，m是个数，n是和，打印所有和为n的 二维数组，注意兼顾性能。
 例子：
 arr 为[-1，1，2，3，4，5，6]
 m=2, n=5时，打印 [  [1，4]，[2，3]，[-1，6] ]
 m=3, n=6时，打印[ [-1，1，6], [-1,2,5], [-1,3,4], [1,2,3] ]
 */
void help(vector<vector<int>> &res, vector<int>&tmp, vector<int> &arr, vector<bool> &isVisited, int m, int n, int k){
    if(tmp.size() == m){
        if(n == 0)
            res.push_back(tmp);
        return;
    }
    for (int i = k; i < arr.size(); i++) {
        if(!isVisited[i]){
            isVisited[i] = true;
            tmp.push_back(arr[i]);
            help(res, tmp, arr, isVisited, m, n-arr[i], i);
            tmp.pop_back();
            isVisited[i] = false;
        }
    }
}
void foo(vector<int> &arr, int m, int n){
    int L = (int)arr.size();
    vector<bool> isVisited(L, false);
    vector<vector<int>> res;
    vector<int> tmp;
    
    help(res, tmp, arr, isVisited, m, n, 0);
    if(res.size() == 0) return;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout<<res[i][j]<<", ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int> arr = {-1,1,2,3,4,5,6};
    foo(arr, 3, 6);
    cout<<"Hello world"<<endl;
    //return 0;
}



