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
    ~Singleton(){};
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
public:
    static Singleton& getInstance()
    {
        static Singleton* singleton;
        return singleton;
    }
};

int main(){
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    if(p1 == p2)
        printf("一致对象\n");
    else
        printf("不一致对象\n");
}
