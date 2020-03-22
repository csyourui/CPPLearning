//
//  4_迷路的牛牛.cpp
//  LeetCode_Answer
//
//  Created by yourui on 2020/3/18.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 
 输入描述：
 *****************************************************************
 *每个输入包含一个测试用例。
 *每个测试用例的第一行包含一个正整数,表示转方向的次数N(N<=1000).
 *接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转.
 *****************************************************************
 输出描述：
 *****************************************************************
 *输出牛牛最后面向的方向,N表示北,S表示南, E表示东, W表示西.
 *****************************************************************
 
 */
#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    string direction[4] = {"N","E","S","W"};
    while(cin >> N){
        string str;
        cin >> str;
        int count = 0;
        for(int i = 0; i < N; i++){
            if(str[i] == 'L') count--;
            if(str[i] == 'R') count++;
            if(count < 0) count = 3;
            if(count > 3) count = 0;
        }
        cout<<direction[count]<<endl;
    }
}
