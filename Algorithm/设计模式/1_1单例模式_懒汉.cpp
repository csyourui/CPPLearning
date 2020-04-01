//
//  1_1单例模式_懒汉.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/29.
//  Copyright © 2020 yourui. All rights reserved.
//

/*
 懒汉式，请不请求时没有产生对象才产生唯一一个对象
 */
#include <stdio.h>
class Singleton{
private:
    Singleton(){};
public:
    static Singleton* singleton;
    static Singleton* getInstance();
};
Singleton* Singleton::singleton = nullptr;
Singleton* Singleton::getInstance(){
    if(Singleton::singleton == nullptr)
        return Singleton::singleton;
    else
        return new Singleton();
}

int main(){
    Singleton* a = Singleton::getInstance();
    Singleton* b = Singleton::getInstance();
    if(a == b) printf("Same Instance\n");
    else printf("Not Same Instance\n");
}
