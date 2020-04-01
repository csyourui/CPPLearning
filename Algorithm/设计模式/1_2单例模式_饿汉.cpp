//
//  1_2单例模式_饿汉.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/29.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 饿汉式， 无论请不请求默认都产生一个对象
 */
#include <stdio.h>
class Singleton{
private:
    Singleton(){};
public:
    static Singleton* singleton;
    static Singleton* getInstance();
};
Singleton* Singleton::singleton = new Singleton();
Singleton* Singleton::getInstance(){
    return Singleton::singleton;
}

int main(){
    Singleton* a = Singleton::getInstance();
    Singleton* b = Singleton::getInstance();
    if(a == b) printf("Same Instance\n");
    else printf("Not Same Instance\n");
}
