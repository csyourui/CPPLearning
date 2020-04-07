//
//  单例模式_懒汉.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/6.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

 
void shellSort(vector<int> &v){
    int h = 1, N = (int)v.size();
    while(h < N/3)
        h = 3*h + 1;
    while(h >= 1){
        for (int i = h; i < N; i++) {
            for(int j = i;j >= h && v[j] < v[j-h]; j -= h){
                swap(v[j], v[j-h]);
            }
        }
        h /= 3;
    }
}
int main(){
    vector<int> v = {1,12,0,8,2,3,5,9,10,6,7,4,11};
    shellSort(v);
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }
}
