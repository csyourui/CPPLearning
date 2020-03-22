//
//  最长公共子序列.cpp
//  test
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//最长公共子序列（不连续）
/*
 
dp(i, j) = 0                            如果 i == 0 || j == 0
dp(i, j) = dp(i-1, j-1)+1               如果 str1[i] == str2[j]
dp(i, j) = max(dp(i, j-1), dp(i-1, j))  如果 str1[i] != str2[j]
 
 */
int LCS(string str1, string str2){
    int M = (int) str1.length(), N = (int) str2.length();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1));
    vector<vector<int>> dir(M + 1, vector<int>(N + 1));

    int i, j;

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i] == str2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 0;//左上
            }
            else if (dp[i][j - 1] >= dp[i - 1][j]){
                dp[i][j] = dp[i][j - 1];
                dir[i][j] = -1;//左
            }
            else if (dp[i][j - 1] < dp[i - 1][j]){
                dp[i][j] = dp[i - 1][j];
                dir[i][j] = 1;//上
            }
        }
    }
    
    return dp[M][N];

}

int main(){
    string str1 = "abaymourui";
    string str2 = "yomurhppy";
    cout<<LCS(str1, str2)<<endl;
}
