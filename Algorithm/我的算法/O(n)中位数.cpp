//
//  O(n)中位数.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/20.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& v, int start, int end) {
    int pivot = v[start];
    while (start < end) {
        while(start < end && v[end] >= pivot) end--;
        v[start] = v[end];
        while (start < end && v[start] <= pivot) start++;
        v[end] = v[start];
    }
    v[start] = pivot;
    return start;
}
int parition(vector<int>&v, int start, int end){
    int key = v[start];
    int i = start + 1;
    int j = end;
    while (true) {
        while(i < end && v[i] < key) i++;
        while(j > start && v[j] > key) j--;
        if(i>=j) break;
        swap(v[i], v[j]);
    }
    swap(v[start], v[j]);
    return j;
}

double findMid(vector<int> &v){
    if(v.size() == 0) return -1;
    int left = 0, right = (int)v.size()-1;
    int mid = left + (right - left)/2;
    int index = -1;
    while (index != mid) {
        index = parition(v, left, right);
        if(index < mid) left = index + 1;
        else if(index > mid) right = index - 1;
        else break;
    }
    if(v.size() % 2 == 1)
        return v[index];
    else
        return v[index] / 2.0 + v[index+1] / 2.0;
}


int main(){
    vector<int> v0 = {5, 4 ,3, 1, 6, 9, 8};
    //0 1 2 3 4 5 6 7 8 9 10 11
    vector<int> a = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    cout<<findMid(a)<<endl;


    return 0;
}

