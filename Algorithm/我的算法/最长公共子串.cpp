//
//  最长公共子串.cpp
//  test
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//最长公共子串（连续！！）
/*
 
dp(i, j) = 0                            如果 i == 0 || j == 0
dp(i, j) = dp(i-1, j-1)+1               如果 str1[i] == str2[j]
 
 */
string LCS(string str1, string str2){
    int M = (int) str1.length(), N = (int) str2.length();
    vector<vector<int>> dp(M + 1 , vector<int>(N + 1, 0));
    int maxLength = 0;
    string res;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
             if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;
        }
    }
    int x, y;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if(dp[i][j] && dp[i][j] > maxLength){
                maxLength = dp[i][j];
                x = i;
                y = j;
            }
        }
    }
    for (int i = 0; i < maxLength; i++) {
        res += str1[x - maxLength + i];
    }
    return res;
}

int main(){
    string str1 = "abafyouruifsfssfsd";
    string str2 = "fsdfsfsdafyouruihppy";
    cout<<LCS(str1, str2)<<endl;
}

