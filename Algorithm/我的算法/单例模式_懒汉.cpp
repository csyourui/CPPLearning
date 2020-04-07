//
//  单例模式_懒汉.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/6.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
class Singleton{
public:
    static Singleton* getInstance(){
        if (singleton == nullptr) {
            singleton = new Singleton();
        }
        return singleton;
    }
private:
    Singleton(){}; //私有构造函数，不允许使用者自己生成对象
    Singleton(const Singleton& other) = default;
    Singleton& operator=(const Singleton& other) = default;
    static Singleton* singleton; //静态成员变量
};

Singleton* Singleton::singleton=nullptr; //静态成员需要先初始化

int main(){
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    if(p1 == p2)
        printf("一致对象\n");
    else
        printf("不一致对象\n");
}
