//
//  单例模式双重校验锁.cpp
//  C++Learning
//
//  Created by yourui on 2020/9/5.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <mutex>
#include <thread>

class Singleton {
 private:
  Singleton() {}
  static std::mutex *mtx;
  static Singleton *instance;

 public:
  int val;
  static Singleton *getInstance() {
    if (instance == nullptr) {
      mtx->lock();
      if (instance == nullptr) {
        instance = new Singleton;
      }
      mtx->unlock();
    }
    return instance;
  }
};
std::mutex *Singleton::mtx = new std::mutex;
Singleton *Singleton::instance = nullptr;  //  静态成员需要先初始化

int main() {
  Singleton *i1 = Singleton::getInstance();
  i1->val = 333;
  Singleton *i2 = Singleton::getInstance();
  std::cout << i2->val << std::endl;
}

