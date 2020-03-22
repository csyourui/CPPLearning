//
//  ReverseStr.cpp
//  test
//
//  Created by yourui on 2020/2/24.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string reverseStr(string str, int index){
    return str.substr(index)+str.substr(0,index);
}
int main(){
    string str1, str2;
    string inpuStr;
    while (cin >> inpuStr) {
        for (int i = 0; i < inpuStr.length(); i++) {
            if(inpuStr[i] == ';'){
                str1 = inpuStr.substr(0,i);
                str2 = inpuStr.substr(i+1);
                break;
            }
        }
        
        if (str1.length() != str2.length()) {
            cout<<"false"<<endl;
            return 0;
        }
        else{
            for (int i = 0; i < str1.length(); i++) {
                if (reverseStr(str1, i) == str2) {
                    cout<<"true"<<endl;
                    return 0;
                }
            }
        }
        cout<<"false"<<endl;
    }
}
