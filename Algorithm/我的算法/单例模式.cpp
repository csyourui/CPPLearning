//
//  单例模式.cpp
//  test
//
//  Created by yourui on 2020/3/10.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
class Singleton{
private:
    Singleton(){};
    static Singleton * singleton;
public:
    static Singleton* getInstance(){
        if(singleton==nullptr){
            printf("创建实例\n");
            singleton = static new Singleton();
        }
        return singleton;
    }
};
Singleton *Singleton::singleton = nullptr;

int main(){
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    Singleton temp;
    if(p1 == p2)
        printf("一致对象\n");
    else
        printf("不一致对象\n");
    printf("sizeof(Singleton) = %d\n", sizeof(Singleton));
}
