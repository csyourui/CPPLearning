//
//  5_替换空格.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
//从头遍历，遇到空格计数器从length开始+2，p1从length-1开始向前，p2从count-1开始向前
//p1遇到空格，p2开始逆序赋值为‘0’‘2’‘%’
void replaceSpace(char *str,int length) {
    int count = length;
    for(int i = 0; i < length; i++){
        if(str[i]==' ')
            count += 2;
    }
    int p2 = count-1, p1 = length -1;
    while(p1 >=0 && p2 >=0 && p1 < p2){
        char c = str[p1--];
        if(c == ' '){
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
        }else{
            str[p2--] = c;
        }
    }
}
