//
//  Card.cpp
//  test
//
//  Created by yourui on 2020/2/23.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string dominoes;
    while(cin >> dominoes){
        int N =(int) dominoes.length();
        vector<int> A(N,0);
        vector<int> S(N,0);
        int value = 0;
        for(int i = 0; i < N; i++){
            if(dominoes[i] == 'R')
                value = N;
            else if(dominoes[i] == 'L')
                value = 0;
            else
                value = max(value - 1, 0);
            A[i] = value;
        }
        value = 0;
        for(int i = N-1; i >= 0; i--){
            if(dominoes[i] == 'L')
                value = N;
            else if(dominoes[i] == 'R')
                value = 0;
            else
                value = max(value - 1, 0);
            S[i] = -value;
        }
        string ans;
        for(int i = 0; i < N; i++){
            int temp = A[i] + S[i];
            if(temp == 0) ans.push_back('.');
            if(temp > 0) ans.push_back('R');
            if(temp < 0) ans.push_back('L');
        }
        cout<<ans<<endl;
    }
}
