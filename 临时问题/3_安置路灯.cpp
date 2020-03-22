//
//  3_安置路灯.cpp
//  LeetCode_Answer
//
//  Created by yourui on 2020/3/18.
//  Copyright © 2020 yourui. All rights reserved.
//

/*
 小Q正在给一条长度为n的道路设计路灯安置方案。
 为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。
 小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。
 小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。
 */
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int t, n;
    while(cin >> t) {
        vector<int> ans(t);
        for(int i = 0; i < t; i++){
            int n;
            string s;
            cin>>n;
            cin>>s;
            
            for(int k = 0; k < n;){
                if(s[k]=='.') {
                    ans[i]++;
                    k = k + 3;
                }
                else{
                    k = k + 1;
                }
            }
        }
        for(int i = 0; i < t; i++){
            cout<<ans[i]<<endl;
        }
    }
}
