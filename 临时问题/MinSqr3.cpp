//
//  MinSqr3.cpp
//  test
//
//  Created by yourui on 2020/2/27.
//  Copyright © 2020 yourui. All rights reserved.
//

//1
//8
//27
//dp[N] = min{dp[N-27]+1,dp[N-8]+1,dp[N-1]+1}
//dp[28] = min{dp[1]+1,dp[20]+1,dp[20]+1}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int N;
    while (cin >> N){
        vector<int> dp(N+1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = INT_MAX;
            for(int j = 1; j <= 100 && (j*j*j) <= i; j++){
                dp[i] = min(dp[i], dp[i-j*j*j]+1);
            }
        }
        cout<<dp[N]<<endl;
    }
}
