//
//  12_矩阵中的路径.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

int M;
int N;
bool backtrack(vector<vector<char>> &Matrix,vector<vector<bool>> &isVisited, int i, int j, string str, int count){
    if(isVisited[i][j] || Matrix[i][j] != str[count]) return false;
    if(count == (int)str.length()-1)return true;
    isVisited[i][j] = true;
    if (i-1>=0 && backtrack(Matrix,isVisited, i-1, j, str, count+1))
        return true;
    if(i+1<M && backtrack(Matrix,isVisited, i+1, j, str, count+1))
        return true;
    if(j-1>=0 && backtrack(Matrix,isVisited, i, j-1, str, count+1))
        return true;
    if(j+1<N && backtrack(Matrix,isVisited, i, j+1, str, count+1))
        return true;
    isVisited[i][j] = false;
    return false;
}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
    M = rows;
    N = cols;
    vector<vector<char>> Matrix(M, vector<char>(N, ' '));
    vector<vector<bool>> isVisited(M, vector<bool>(N, false));
    string S = string(str);
    int k = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            Matrix[i][j] = matrix[k++];
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(backtrack(Matrix,isVisited,i , j, S, 0))
                return true;
        }
    }
    return false;
}
