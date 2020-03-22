//
//  AssestPackage.cpp
//  test
//
//  Created by yourui on 2020/2/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int backtrack(int i, int M, int C, vector<int> T, vector<int> V){
    if(i == T.size() || M == 0)
        return C;
    if(M >= T[i])
        return max(backtrack(i+1, M, C, T, V), backtrack(i+1, M-T[i], C+V[i], T, V));
    else
        return backtrack(i+1, M, C, T, V);
}
//12 3 4 5 7 500 600 800
int main(){
    int M, N;
    char C;
    while(cin >> M >> C >> N >> C){
        vector<int> T(N+1);
        vector<int> V(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> T[i];
        }
        cin >> C;
        for (int i = 1; i <= N; i++) {
            cin >> V[i];
        }
        vector<vector<int>> dp(N+1,vector<int>(M+1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if( j >=  T[i]){
                    dp[i][j] = max(dp[i-1][j], dp[i - 1][j - T[i]] + V[i]);
                }
            }
        }
        cout<<dp[N][M]<<endl;
    }
}
