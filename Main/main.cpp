#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void oper(vector<int> &v){
    unsigned long N = v.size();
    vector<int> B(N);
    int k = 0;
    int x0 =(int) N/2;
    B[x0] = v[k++];
    int index = 1;
    while(k < v.size()){
        if(N % 2==0){
            if(index % 2 == 1){
                x0 += -1 * index;
            }else{
                x0 += 1 * index;
            }
        }else{
            if(index % 2 != 1){
                x0 += -1 * index;
            }else{
                x0 += 1 * index;
            }
        }
        index++;
        B[x0] = v[k++];
    }
    v = B;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    oper(v);
    cout<<v[0];
    for(int i = 1; i < n; i++){
        cout<<" "<<v[i];
    }
    cout<<endl;
}
