//
//  17_ 打印从1到最大的n位数.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
string addOne(string str1, string str2 = "1"){
    string res = "";
    int carry = 0;
    int l1 = (int)str1.length()-1, l2 = 0;
    while(l1 >=0 || l2 >=0 || carry){
        int sum = (l1>=0)?str1[l1]-'0':0 + (l2>=0)?str2[l2]-'0':0 + carry;
        carry = a /10;
        sum %= 10;
        res.append(sum+'0');
        l1 = (l1>=0)?l1-1:l1;
        l2 = (l2>=0)?l2-1:l2;
    }
    return res;
    
}
void printOneToMM(int n){
    
}

int main(){
    cout<<addOne("999");
}
