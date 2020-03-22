#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct Block{
    int W;
    int L;
};
bool cmp1(Block &a, Block &b){
    return a.W == b.W ? a.L < b.L : a.W < b.W;
}
int binary_search(Block *a, int R, Block X){
    int L = 0, mid;
    while (L <= R) {
        mid = (L + R) / 2;
        if(a[mid].L <= X.L)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return L;
}

int main(){
    int N;
    cin >> N;
    Block *A = new Block[N];
    Block *B = new Block();
    for(int i = 0; i < N; i++){
        cin >> A[i].W >>A[i].L;
    }
    sort(A, A+N, cmp1);
    for(int i = 0; i < N; i++){
        cout << A[i].W << A[i].L << endl;
    }
    
    int len = 1;
    B[len - 1] = A[len - 1];
    for (int i = 1; i < N; i++) {
        if(A[i].L >= B[len - 1].L){
            B[++len - 1] = A[i];
        }
        else
            B[binary_search(B, len - 1, A[i])] = A[i];
    }
    cout<<len<<endl;
}
