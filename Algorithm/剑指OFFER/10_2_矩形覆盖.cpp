//
//  10_2_矩形覆盖.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
int rectCover(int number) {
    vector<int> dp(number+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= number; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[number];
}
