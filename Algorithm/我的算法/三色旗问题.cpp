//
//  ThreeColor.cpp
//  main
//
//  Created by yourui on 2020/3/9.
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
void sortColors(vector<int>& nums) {
    int left = 0, i = 0, right = nums.size() - 1;
    while(i <= right){
        if(nums[i]==0){
            swap(nums[i], nums[left]);
            left++;
            i++;
        }
        else if(nums[i]==2){
            swap(nums[i], nums[right]);
            right--;
        }
        else
            i++;
            
    }
}

int main(){
    vector<int> v = {2,0,1};
    sortColors(v);
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    
}
