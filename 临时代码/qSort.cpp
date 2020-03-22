//
//  qSort.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/2.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

int quick_sort_helper(vector<int> &data, int left, int right){
    int key = data[left];
    while (left < right) {
        //从right开始向left查找，直到找到第一个小于key的元素
        while (left < right && key <= data[right])
            right--;
        //并把该元素赋给left位置的元素
        if(left < right)
            data[left++] = data[right];
        //从left向right查找,直到找到第一个大于等于key的元素
        while (left < right && key > data[left])
            left++;
        if(left < right)
            data[right--] = data[left];
    }
    data[left] = key;
    return left;
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
bool quick_sort(vector<int> &data, int left, int right){
    if (right <= left) return true;
    int i = left+1, j = right, key = data[left];
    while (true){
        /*从左向右找比key大的值*/
        while (data[i] < key && i < right){
            i++;
        }
        /*从右向左找比key小的值*/
        while (data[j] > key && j > left){
            j--;
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        swap(data[i], data[j]);
    }
    /*中枢值与j对应值交换*/
    swap(data[left], data[j]);
    return quick_sort(data, left, j - 1) && quick_sort(data, j + 1, right);
}
int main(){
    vector<int>a = {7, 1, 11, 2, 10, 3, 9, 4, 8, 5, 6};
    cout<<quick_sort(a, 0, (int)a.size()-1)<<endl;
    for(auto x:a){
        cout<<x<<" ";
    }
    cout<<endl;
}
