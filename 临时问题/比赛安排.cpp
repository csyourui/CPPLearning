//
//  比赛安排.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/24.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int K;
    printf("请输入参赛的队伍数量：");
    scanf("%d", &K);
    int N = pow(2, K);
    int Map[N][N];
    Map[0][0] = 1;
    for (int i = 0; i < K; i++) {
        int L = pow(2, i);
        for(int m = 0; m < L; m++){
            for(int n = 0; n < L; n++){
                //左下角为左上角+L
                Map[m+L][n] = Map[m][n] + L;
                //右上角为左上角+L
                Map[m][n+L] = Map[m][n] + L;
                //右下角等于左上角
                Map[m+L][n+L] = Map[m][n];
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", Map[i][j]);
        }
        printf("\n");
    }
}
