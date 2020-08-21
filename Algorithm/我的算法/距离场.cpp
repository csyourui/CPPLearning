//
//  距离场.cpp
//  C++Learning
//
//  Created by yourui on 2020/8/20.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int di[] = {1, 0, -1, 0};
int dj[] = {0, -1, 0, 1};
void dfs(int **map, int i, int j, int m, int n) {
    if (map[i][j] != 0) {
        map[i][j] = 0;
        for (int dir = 0; dir < 4; dir++) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni >= 0 && ni < m && nj >=0 && nj < n && map[ni][nj] != 0) {
                dfs(map, ni, nj, m, n);
            }
        }
    }
}

void bfs(int **map, int m, int n) {
    queue<pair<int,int>> Q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0) {
                Q.push({i, j});
            }
        }
    }
    while (!Q.empty()) {
        auto front = Q.front();
        Q.pop();
        int i = front.first;
        int j = front.second;
        for (int dir = 0; dir < 4; dir++) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni >= 0 && ni < m && nj >=0 && nj < n && map[ni][nj] != 0 && map[i][j] + 1 < map[ni][nj]) {
                map[ni][nj] = map[i][j] + 1;
                Q.push({ni, nj});
            }
        }
    }
}
int** calculateDF(int **map, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j] != 0) {
                map[i][j] = INT_MAX;
            }
        }
    }
    bfs(map, m, n);
    int **nmap = new int*[m];
    for (int i = 0; i < m; i++) {
        nmap[i] = new int[n];
        for (int j = 0; j < n; j++) {
            nmap[i][j] = map[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        if (nmap[i][0] != 0) {
            dfs(nmap, i, 0, m, n);
        }
        if (nmap[0][i] != 0) {
            dfs(nmap, 0, i, m, n);
        }
        if (nmap[i][n-1] != 0) {
            dfs(nmap, i, n-1, m, n);
        }
        if (nmap[m-1][i] != 0) {
            dfs(nmap, m-1, i, m, n);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(nmap[i][j]) {
                map[i][j] = -1;
            }
        }
    }
    return map;
}
int main(){
    int map[6][6] = {
        {1,  1,  1,  1,  1, 1},
        {1,  0,  0,  0,  1, 1},
        {1,  0, -1,  0,  0, 1},
        {1,  0, -1, -1,  0, 1},
        {1,  0,  0,  0,  0, 1},
        {1,  1,  1,  1,  1, 1}
    };
    int **arr=new int*[6];
    arr[0]=map[0];
    arr[1]=map[1];
    arr[2]=map[2];
    arr[3]=map[3];
    arr[4]=map[4];
    arr[5]=map[5];
    int **res = calculateDF(arr, 6, 6);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << res[i][j] <<" ";
        }
        cout <<endl;
    }
}


