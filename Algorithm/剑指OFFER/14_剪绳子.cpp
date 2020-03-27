//
//  14_剪绳子.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
int integerBreak(int n) {
    vector<int> dp(60);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 4;
    dp[5] = 6;
    dp[6] = 9;
    for(int i = 7; i <=n; i++){
        dp[i] = INT_MIN;
        for(int j = 1; j <=3; j++){
            dp[i] = max(dp[i], j * dp[i-j]);
        }
    }
    return dp[n];
}
