//
//  Divide.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define N 10000
using namespace std;

int main(){
    int a, b;
    while (cin >> a >> b) {
        vector<int> decimal;
        map<int, int> myMap;;
        int A = a / b;
        string B = "";
        a %= b;
        if(a != 0) B += ".";
        int count = 0;
        myMap[a] = count++;
        while(a!= 0 && count < N){
            if(myMap[a] != 0) {
                B += ")";
                B.insert(myMap[a], "(");
                break;
             }
            B += to_string(a * 10 / b);
            myMap[a] = count++;
            a = a * 10 % b;
        }
        cout<<A<<B<<endl;
    }
}
