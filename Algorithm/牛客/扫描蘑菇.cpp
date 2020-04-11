//
//  扫描蘑菇.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/10.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int M;
int N;

bool valid(int i, int j){
    return (i >= 1 && i <= M && j >= 1 && j <= N);
}
int countNumber(vector<vector<int>> Map, int i, int j){
    int res = 0;
    for(int di = -1; di <= 1; di++){
        for(int dj = -1; dj <= 1; dj++){
            if(valid(i+di,j+dj) && Map[i+di][j+dj]) res++;
        }
    }
    return res;
}
int clean(vector<vector<int>> &Map){
    int maxN = 0;
    int maxi, maxj;
    for(int i = 1; i <= M - 1; i++){
        for(int j = 1; j <= N - 1; j++){
            int tmp = countNumber(Map, i, j);
            if(tmp > maxN){
                maxi = i;
                maxj = j;
                maxN = tmp;
            }
        }
    }
    int res = 0;
    for(int di = -1; di <= 1; di++){
        for(int dj = -1; dj <= 1; dj++){
            if(valid(maxi+di,maxj+dj) && Map[maxi+di][maxj+dj]){
                res++;
                Map[maxi+di][maxj+dj]--;
            }
        }
    }
    return res;
}
int main(){
    int K, x, y;
    while(~scanf("%d %d %d", &N, &M, &K)){
        vector<vector<int>> Map(M+1, vector<int>(N+1, 0));
        for(int i = 0; i < K; i++){
            scanf("%d %d", &x, &y);
            Map[x][y]++;
        }
        int res = 0;
        res += clean(Map);
        res += clean(Map);
        printf("%d\n", res);
    }
}
