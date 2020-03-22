#include <stdio.h>
#define M 4
#define N 4

int main(){
    int matrix[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int iDir[4] = {0,1,0,-1};
    int jDir[4] = {1,0,-1,0};
    _Bool visited[M][N] = {0};
    int i = 0, j = 0, d = 0, newi, newj;
    printf("%d ",matrix[i][j]);
    int count = 1;
    visited[i][j] = 1;
    while(count < M*N){
        d %= 4;
        newi = i+iDir[d];
        newj = j+jDir[d];
        if(newi >=0 && newi < M && newj >= 0 && newj< N)
        {
            if(!visited[newi][newj]){
                visited[newi][newj] = 1;
                i = newi;
                j = newj;
                printf("%d ",matrix[i][j]);
                count++;
            }
            else
                d++;
        }
        else
            d++;
    }
    printf("\n");
    return 0;
}
