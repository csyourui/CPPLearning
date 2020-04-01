//
//  lower_bound.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/6.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int my_lower_bound(int *a, int begin, int end, int val){
    while(begin <= end){
        int mid = (begin + end) >> 1;
        if (a[mid] >= val)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return begin;
}
int my_upper_bound(int *a, int begin, int end, int val){
    while(begin <= end){
        int mid = (begin + end) >> 1;
        if (a[mid] > val)
            end = mid - 1;
        else
            begin = mid + 1;

    }
    return begin;
}

int my_binary_search(int *vec, int begin, int end, int target){
    while(begin <= end){
        int mid = (begin + end) >> 1;
        if(target > vec[mid])
            begin = mid + 1;
        if(target < vec[mid])
            end = mid - 1;
        if(target == vec[mid])
            return mid;
    }
    return begin;
}

int main(){
    int target  = 4;
    int num[6]={1,2,4,7,15,34};
    sort(num,num+6);                           //按从小到大排序
    int pos1 = my_lower_bound(num,0,6,target);
    int pos2 = my_upper_bound(num,0,6,target);
    int pos3 = my_binary_search(num,0,6,target);
    
    int pos4 = lower_bound(num,num+6,target)-num;
    int pos5 = upper_bound(num,num+6,target)-num;
    cout<<"num = "<<target<<endl;
    for (int i = 0; i < 6; i++) {
        cout<<i<<"\t";
    }
    cout<<endl;
    for (int i = 0; i < 6; i++) {
        cout<<num[i]<<"\t";
    }
    cout<<endl;
    cout<<"插入位置\n";
    cout<<"我的实现binary_search:\t "<<pos3<<" "<<num[pos3]<<endl;
    cout<<"lower_bound 第一个大于或等于num的数字，找到返回该数字的地址\n";
    cout<<"我的实现lower_bound:\t "<<pos1<<" "<<num[pos1]<<endl;
    cout<<"系统实现lower_bound:\t "<<pos4<<" "<<num[pos4]<<endl;
    cout<<"upper_bound 第一个大于num的数字，找到返回该数字的地址\n";
    cout<<"我的实现upper_bound:\t "<<pos2<<" "<<num[pos2]<<endl;
    cout<<"系统实现upper_bound:\t "<<pos5<<" "<<num[pos5]<<endl;
    return 0;
}
