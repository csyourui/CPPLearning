//
//  1_9最大子矩阵的大小.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/20.
//  Copyright © 2020 yourui. All rights reserved.
//

/*
输入：
 
 3 4
 1 0 1 1
 1 1 1 1
 1 1 1 0
输出：
 res
*/



#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int maxFromBottom(vector<int> &height){
    
}
int maxRecSize(vector<vector<int>> map, int M, int N){
    int maxAera = INT_MIN;
    vector<int> height(N, 0);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            height[j] = map[i][j] == 0 ? 0 : height[j] + 1;
        }
        maxAera = max(maxAera, maxFromBottom(height));
    }
    return maxAera;
}
int main(){
    int M, N;
    while(cin >> M >> N){
        vector<vector<int>> Map(M, vector<int>(N, 0));
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cin >> Map[i][j];
            }
        }
        cout<<maxRecSize(Map, M, N)<<endl;
    }
}

