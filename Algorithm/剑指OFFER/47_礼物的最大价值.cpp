//
//  47_礼物的最大价值.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/7.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxP(vector<vector<int>> &map){
    int m = map.size(), n = map[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + map[i-1][j-1];
        }
    }
    return dp[m][n];
}
int main(){
    vector<vector<int>> map = {
        {1, 10, 3, 8},
        {12, 2, 9, 6},
        {5, 7, 4, 11},
        {3, 7, 16, 5}};
    cout<<maxP(map)<<endl;
}
