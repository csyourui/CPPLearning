//
//  LIS2.cpp
//  test
//
//  Created by yourui on 2020/2/26.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int find(string str, int i, int j, string &ansStr){
    int count = 0;
    if(i == j)
        count = -1;
    while(i>=0 && j <(int)str.length() && str[i] == str[j]){
        count = count + 2;
        i--;
        j++;
    }
    ansStr = str.substr(i+1,count);
    return count;
}
int main(){
    string str = "";
    while (cin >> str){
        int maxLength = 0;
        string maxStr = "";
        for (int i = 0; i < str.length(); i++) {
            string tempStr = "";
            int a = find(str, i, i, tempStr);
            if(a > maxLength){
                maxStr = tempStr;
                maxLength = a;
            }
            a = find(str, i, i + 1, tempStr);
            if(a > maxLength){
                maxStr = tempStr;
                maxLength = a;
            }
        }
        cout<<maxStr<<endl;
    }
}
