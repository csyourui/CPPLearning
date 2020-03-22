//
//  LIS.cpp
//  test
//
//  Created by yourui on 2020/2/19.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> a, int R, int X){
    //数组a中返回第一个 >= x 的值
    int L = 0, mid;
    while (L <= R) {
        mid = (L + R) / 2;
        if(a[mid] <= X)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return L;
}
int main(){
    vector<int> A = {3,1,2,6,4,5,5,7};
    //vector<int> A = {1,4,7,2,5,9,10,3};

    vector<int> B;
    int len = 1;
    B.push_back(A[0]);
    for(int i = 1; i < A.size(); i++){
        if(A[i] >= B[len - 1]){
            len++;
            B.push_back(A[i]);
        }
        else{
            //B[binary_search(B, len-1, A[i])] = A[i];
            *lower_bound(B.begin(), B.end(), A[i]) = A[i];
        }
    }
    for(auto x:B)
        cout<<x<<" ";
    cout<<endl;
    cout<<len<<endl;
}
