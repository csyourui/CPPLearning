//
//  字符匹配.cpp
//  test
//
//  Created by yourui on 2020/3/16.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    if(p.empty()) return s.empty();
    if(s.empty()) return false;
    int I = (int)s.length(), J = (int)p.length();
    vector<vector<bool>> dp(I+1, vector<bool>(J+1));
    for(int i = 0; i <= I; i++)
        dp[i][0] = false;
    dp[0][0] = true;
     for (int j = 0; j < J; j++) { // here's the p's length, not s's
         if (p[j] == '*' && dp[0][j - 1]) {
             dp[0][j + 1] = true; // here's y axis should be i+1
         }
     }
    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            if(p[j] == s[i] || p[j] == '.') dp[i+1][j+1] = dp[i][j];
            if(p[j] == '*' ){
                if(p[j-1] != s[i] && p[j-1]!= '.')
                    dp[i+1][j+1] = dp[i+1][j-1];
                else
                    dp[i+1][j+1] = dp[i+1][j-1]||dp[i][j+1]||dp[i+1][j];
            }
        }
    }
    return dp[I][J];
}
int main(){

    string s = "mississippi";
    string p = "mis*is*p*.";
    if(isMatch(s, p))
        cout<<"匹配成功"<<endl;
    else
        cout<<"匹配失败"<<endl;
}
