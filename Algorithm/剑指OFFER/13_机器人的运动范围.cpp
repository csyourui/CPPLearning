//
//  13_机器人的运动范围.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

//下，右，上， 左
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0, -1}};
int sumOD(int i, int j){
    int res = 0;
    while(i){
        res += i % 10;
        i /= 10;
    }
    while(j){
        res += j % 10;
        j /= 10;
    }
    return res;
}
int movingCount(int threshold, int rows, int cols)
{
    if(threshold<0) return 0;
    vector<vector<bool>> M(rows, vector<bool>(cols, false));
    queue<pair<int, int>> Q;
    Q.push({0,0});
    M[0][0] = true;
    int res = 0;
    while(!Q.empty()){
        res++;
        auto t = Q.front(); Q.pop();
        for(int n = 0; n < 4; n++){
            int ni = t.first + dir[n][0], nj = t.second + dir[n][1];
            if(ni>=0 && ni <rows && nj>=0 && nj<cols && !M[ni][nj] && sumOD(ni,nj)<=threshold ){
                M[ni][nj] = true;
                Q.push({ni, nj});
            }
        }
    }
    return res;
}
