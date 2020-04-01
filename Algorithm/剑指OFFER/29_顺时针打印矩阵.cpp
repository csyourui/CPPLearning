//
//  29_顺时针打印矩阵.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

int iDir[4] = {0,1,0,-1};
int jDir[4] = {1,0,-1,0};
// 1  2  3  4
// 5  6  7  8
// 9 10 11 12
//13 14 15 16
vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> ans;
    int M = matrix.size(), N = matrix[0].size();
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    int i = 0, j = 0, d = 0, newi, newj;
    ans.push_back(matrix[i][j]);
    visited[i][j] = true;
    while(true){
        if(ans.size()==M*N) break;
        d %= 4;
        newi = i+iDir[d];
        newj = j+jDir[d];
        if(newi >=0 && newi < M && newj >= 0 && newj< N && !visited[newi][newj]){
            visited[newi][newj] = true;
            ans.push_back(matrix[newi][newj]);
            i = newi;
            j = newj;
        }
        else
            d++;
    }
    return ans;
}
