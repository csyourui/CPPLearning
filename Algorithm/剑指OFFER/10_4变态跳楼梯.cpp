//
//  10_4变态跳楼梯.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

//f(n) = f(n-1) + f(n-2) + f(n-3) +... + f(0)
//f(n-1) = f(n-2) + f(n-3) + f(n-4) +... + f(0)

//f(n) - f(n-1) = f(n-1)
//f(n) = 2 * f(n-1)等比数列

int jumpFloorII(int number) {
    vector<int> dp(number+1);
    dp[0] = 1;
    for(int i = 1; i <= number; i++){
        for(int j = 1; j <= i; j++){
            dp[i] += dp[i-j];
        }
    }
    return dp[number];
}
