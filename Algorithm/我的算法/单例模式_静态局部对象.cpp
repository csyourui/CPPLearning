//
//  单例模式_静态局部对象.cpp
//
//  Created by yourui on 2020/3/10.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
class Singleton{
private:
    Singleton(){};
    ~Singleton(){};
    Singleton(const Singleton&) = default;
    Singleton& operator=(const Singleton&) = default;
public:
    static Singleton& getInstance()
    {
        static Singleton singleton;
        return singleton;
    }
};

int main(){
    Singleton &p1 = Singleton::getInstance();
    Singleton &p2 = Singleton::getInstance();
    if(&p1 == &p2)
        printf("一致对象\n");
    else
        printf("不一致对象\n");
}
