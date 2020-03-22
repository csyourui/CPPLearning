//
//  SortOne.cpp
//  test
//
//  Created by yourui on 2020/3/7.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<int, int> myMap;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
bool quickSort(vector<int>&arr, int start, int end){
    if(start >= end) return true;
    int key = myMap[arr[start]];
    int i = start + 1, j = end;
    while(i < j){
        while(key > myMap[arr[i]] && i < end)
            i++;
        while(key < myMap[arr[j]] && j > start)
            j--;
        if(i >= j)
            break;
        swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);
    
    return quickSort(arr, start, j - 1) && quickSort(arr, j + 1, end);
}
vector<int> sortByBits(vector<int>& arr) {
    for(int i =0; i < arr.size(); i++){
        if(myMap[arr[i]] == 0){
            int n = 0, x = arr[i];
            while(x){
                n += x & 1;
                x = x>> 1;
            }
            myMap[arr[i]] = n;
            cout<<arr[i]<<" "<<myMap[arr[i]]<<endl;
        }
    }
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}
int main(){
    vector<int> a = {0,1,2,3,4,5,6,7,8};
    sortByBits(a);
    for(int i =0; i < a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
