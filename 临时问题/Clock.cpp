//
//  Clock.cpp
//  test
//
//  Created by yourui on 2020/2/25.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string timeChange(string &str){
    int HH = stoi(str.substr(0,2));
    int MM = stoi(str.substr(3,2));
    int SS = stoi(str.substr(6,2));
    if(HH > 23 || MM > 59 || SS > 59){
        //在这实现
        if(str[0] > '2'||(str[0] == '2' && str[1] > '3'))
            str[0] = '0';
        if(str[3] > '5')
            str[3] = '0';
        if(str[6] > '5')
            str[6] = '0';
    }
    return str;
}
int main(){
    int N;
    while( cin >> N){
        vector<string> str;
        for (int i = 0; i < N; i++) {
            string tempstr = "";
            cin >> tempstr;
            str.push_back(tempstr);
        }
        for (int i = 0; i < N; i++) {
            cout<<timeChange(str[i])<<endl;
        }
    }
}
