//
//  LeftStr.cpp
//  test
//
//  Created by yourui on 2020/3/5.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string LeftRotateString(string str, int n) {
    n %= str.length();
    return str.substr(n) + str.substr(0, n);
}
int main(){
    cout<<LeftRotateString("abcXYZdef", 9)<<endl;
}
