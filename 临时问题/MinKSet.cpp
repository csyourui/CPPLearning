//
//  MinKSet.cpp
//  test
//
//  Created by yourui on 2020/3/2.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void maxHeapify(vector<int> &v, int i, int n){
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    while(c1 < n){
        int max = i;
        if(v[c1] > v[max]) max = c1;
        if(c2 < n && v[c2] > v[max]) max = c2;
        if(max == i) return;
        else{
            swap(v[max], v[i]);
            i = max;
            c1 = i * 2 + 1;
            c2 = i * 2 + 2;
        }
    }
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> minSet(k);
    for(int i = 0; i < k;i++){
        minSet[i] = input[i];
    }
    for(int i = k/2 - 1; i >=0; i--)
        maxHeapify(minSet, i, k);

    for(int i = k; i < input.size();i++){
        if(input[i] < minSet[0]){
            minSet[0] = input[i];
            maxHeapify(minSet, 0, k);
        }
    }
    return minSet;
}
//8 4
//4 5 1 6 2 7 3 8
int main(){
    int N = 8;
    int k = 4;
    srand((unsigned int)time(NULL));
    vector<int> input;
    for (int i = 0; i < N; ++i) {
        int a =rand() % 10;
        input.push_back(a);
        cout<<a<<" ";
    }
    cout<<endl;
    vector<int> ans;
    ans = GetLeastNumbers_Solution(input, k);
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
