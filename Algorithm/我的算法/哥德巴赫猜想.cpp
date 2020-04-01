//
//  哥德巴赫猜想.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/31.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool test(int N){
    //N = P + R
    vector<int> prime;
    prime.reserve(N+1);
    vector<bool> visited(N+1, false);
    visited[1] = true;
    for(int i = 2; i <= N; i++){
        if(!visited[i]){
            for(int j = i * i; j <= N; j += i){
                visited[j] = true;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if(!visited[i]){
            prime.push_back(i);
        }
    }
    
    int i = 0, j = (int)prime.size()-1;
    while(i <= j){
        int t = prime[i] + prime[j];
        if(t > N){
            j--;
        }else if (t < N){
            i++;
        }else{
            //cout<<N<<"="<<prime[i]<<"+"<<prime[j]<<endl;
            return true;
        }
    }
    return false;
}

int main(){
    int N = 2000;
    for(int i = 4; i <= N; i += 2){
        if(!test(i))
            cout<<"这是不可能的"<<endl;
    }
}

