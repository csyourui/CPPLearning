//
//  Find.cpp
//  test
//
//  Created by yourui on 2020/3/5.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int binary_search(vector<int> vec, int target){
    int i = 0, j = vec.size();
    while(i <= j){
        int mid = (i+j) >> 1;
        if(target > vec[mid])
            i = mid + 1;
        if(target < vec[mid])
            j = mid - 1;
        if(target == vec[mid])
            return mid;
    }
    return i;
}
int main(){
    vector<int> v = {1, 2, 4, 6, 9, 11, 13, 14};
    cout<<binary_search(v,4)<<endl;
    cout<<binary_search(v,6)<<endl;
    cout<<binary_search(v,7)<<endl;
    cout<<binary_search(v,3)<<endl;

}
