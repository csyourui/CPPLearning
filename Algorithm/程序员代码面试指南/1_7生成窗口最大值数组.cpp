//
//  1_?生成窗口最大值数组.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/20.
//  Copyright © 2020 yourui. All rights reserved.
//

/*
输入：
 n表示数组元素， k表示窗口大小
输出：
 res
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    int n, w;
    while(cin >> n >> w){
        vector<int> arr(n);
        deque<int> dq;
        vector<int> res;
        
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            //如果队头的下标等于i-w说明已经过期，弹出当前对头的下标
            if(dq.front() == i - w) dq.pop_front();
            if(i >= w - 1) res.push_back(arr[dq.front()]);
        }
        for(int i = 0; i < res.size()-1; i++)
            cout<<res[i]<<" ";
        cout<<res[res.size()-1]<<endl;
    }
}


