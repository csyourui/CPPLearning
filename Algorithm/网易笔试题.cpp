//
//  网易笔试题.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

void printSTR(string str, int M){
    int N = (int)str.length();
    int p1 = 0, p2;
    while(p1 < N){
        for(p2 = p1+1; p2 < N; p2++){
            if(str[p2] != str[p2-1] + 1) break;
        }
        if(p2 - p1 >= M)
            cout<<str[p1]<<"-"<<str[p2-1];
        else{
            for(int i = p1; i < p2; i++)
                cout<<str[i];
        }
        p1 = p2;
    }
    cout<<endl;
}
void jinzhi(int X, int Y, string str){
    int N = (int)str.length();
    int a = 0, b = 0, k = 1;
    int i = 0, j = N-1;
    while(i < j){
        if(a <= b){
            a = X*a+(str[i++]-'0');
        }else{
            b = b+k*(str[j--]-'0');
            k *= Y;
        }
    }
    printf("a = %d\n", a);
}
int main(){
    string str = "XYZABCDHAMHIJKL";
    string number = "113221101000101";
       
    jinzhi(5, 2, number);
    
}
