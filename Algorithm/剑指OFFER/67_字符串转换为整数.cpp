//
//  67_字符串转换为整数.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

int StrToInt(string str) {
    long long res = 0;
    if(str == "") return 0;
    bool isNegative = false;
    char c = str[0];
    int i = 0;
    if(c < '0' || c >'9'){
        i++;
        if(c == '+') isNegative = false;
        else if(c == '-') isNegative = true;
        else return 0;
    }
    while(i < (int)str.length()){
        int n = str[i++]-'0';
        if(n<0||n>9) return 0;
        res = 10*res + n;
    }
    if(isNegative){
        res = -res;
        if(res < INT_MIN) return 0;
    }else{
        if(res > INT_MAX) return 0;
    }
    return res;
}
