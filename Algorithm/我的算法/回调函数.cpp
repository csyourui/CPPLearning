//
//  回调函数.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/25.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
 
void printHello(char *hello){
     printf("%s\n",hello);
}
void printWorld(char *World){
     printf("%s\n",World);
}
void callBack(void(*pFunc)(char *),char *words){
    pFunc(words);
}

int main(void){
    callBack(printHello,"Hello");
    callBack(printWorld,"World");
}
 



