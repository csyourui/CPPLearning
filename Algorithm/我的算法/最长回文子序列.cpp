//
//  最长回文子序列.cpp
//  test
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalindromeSubseq(string s) {
    int N = (int)s.length();
    vector<vector<int>> dp(N, vector<int> (N, 0));
    for(int i = N - 1; i >= 0; i--){
        dp[i][i] = 1;
        for(int j = i + 1; j < N; j++){
            if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][N - 1];
}

int main(){
    string str = "adabada";
    cout<<longestPalindromeSubseq(str)<<endl;
}
