//
//  全排列.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/1.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &res,vector<int> &nums, vector<int> &temp, int length)
{
    if(length  == nums.size()){
        res.push_back(temp);
    }
    for(int i = length; i < nums.size(); i++){
        swap(temp[i], temp[length]);
        dfs(res,nums,temp,length + 1);
        swap(temp[i],temp[length]);
    }
}
void backtrack(vector<vector<int>> &res,vector<bool> &isVisited, vector<int> &nums, vector<int> &temp){
    if(temp.size() == nums.size()){
        res.push_back(temp);
    }
    for (int i = 0; i < nums.size(); i++) {
        if(!isVisited[i]){
            isVisited[i] = true;
            temp.push_back(nums[i]);
            backtrack(res, isVisited, nums, temp);
            temp.pop_back();
            isVisited[i] = false;
        }
    }
}

int main()
{
    int n = 3;
    vector<vector<int>> res;
    vector<int> nums(n);
    vector<int> temp1(n);
    vector<int> temp2;
    vector<bool> isVisited(n, false);

    for(int i = 0;i < n; i++)
    {
        nums[i] = i+1;
        temp1[i] = i+1;
    }
    dfs(res, nums, temp1, 0);
    //backtrack(res, isVisited, nums, temp2);
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}


