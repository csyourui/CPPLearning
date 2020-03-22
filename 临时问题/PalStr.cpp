//
//  PalStr.cpp
//  test
//
//  Created by yourui on 2020/2/20.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str = "";
    while (cin >> str){
        int N = (int) str.length();
        vector<vector<int>> dp(N, vector<int>(N , 0));
        for (int r = 0; r < N; r++) {
            dp[r][r] = 1;
            for (int l = r - 1; l >= 0; l--) {
                if(str[l] == str[r])
                    dp[l][r] = dp[l + 1][r - 1] + 2;
                else
                    dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            }
        }

        cout<<dp[0][N - 1]<<endl;
    }
}
