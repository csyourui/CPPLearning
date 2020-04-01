//
//  67_字符串转换为整数.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int flag = 1;
int myAtoi(const char *str){
    if(str == nullptr || *str == '\0'){
        flag = 0;
        return 0;
    }
    long long res = 0;
    bool negative = false;
    if(*str == '+'){
        str++;
    }else if(*str == '-'){
        str++;
        negative = true;
    }
    //只有正负号时
    if(*str == '\0'){
        flag = 0;
        return 0;
    }
    while(*str != '\0'){
        if(*str < '0' || *str > '9'){
            flag = 0;
            return 0;
        }else{
            res =  res * 10 + *str - '0';
            str++;
        }
    }
    res = negative? -1*res : res;
    if(res < INT_MIN || res > INT_MAX){
        flag = 0;
        return 0;
    }
    return (int) res;
}
int main(){
    char *str = "-312312";
    int res = myAtoi(str);
    if(flag == 0){
        printf("Bad request!\n");
    }else{
        printf("%d\n", res);
    }
    
}
