//
//  大整数乘法.cpp
//  Algorithms
//
//  Created by yourui on 2020/3/19.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string add(string str1, string str2){
    int index1 = (int)str1.length()-1;
    int index2 = (int)str2.length()-1;
    int a, b, carry = 0, sum;
    string res = "";
    while(index1>=0 || index2>=0 || carry){
        a = index1 >= 0 ? str1[index1]-'0': 0;
        b = index2 >= 0 ? str2[index2]-'0': 0;
        sum = a + b + carry;
        carry = sum / 10;
        sum %= 10;
        res.insert(res.begin(), sum + '0');
        index1 = index1 >= 0 ? index1-1 : index1;
        index2 = index2 >= 0 ? index2-1 : index2;
    }
    return res;
}

string multi(string str1, string str2){
    string res = "";
    int index2 = (int)str2.length()-1;
    for(int i = index2; i >=0; i--){
        int c = str2[i]-'0';
        for(int j = 0; j < c; j++){
            res = add(res , str1);
        }
        str1.push_back('0');
    }
    return res;
}
int main(){
    string str1 = "72106547548473106236";
    string str2 = "982161082972751393";
    cout<<multi(str1, str2);
}
