//
//  Egg.cpp
//  test
//
//  Created by yourui on 2020/2/29.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M){
        int **dp = new int*[N+1];
        for (int i = 0; i < N + 1; i++) {
            dp[i] = new int[M+1];
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                dp[i][j] = j;
            }
        }
        //dp[n][m] = 1 + max(dp[n-1][k-1],dp[n][m-k])
        for(int i = 2; i <= N; i++){
            for(int j = 2; j <= M; j++){
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][k-1],dp[i][j-k]));
                }
            }
        }
//        for(int i = 1; i <= N; i++){
//            for(int j = 1; j <= M; j++){
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<dp[N][M]<<endl;
    }
}
