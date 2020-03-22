//
//  汽车工厂模式.cpp
//  test
//
//  Created by yourui on 2020/3/10.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

class AbstractCar{
public:
    virtual void run() = 0;
    virtual ~AbstractCar(){};
};
class BMW : public AbstractCar{
public:
    virtual void run(){
        cout<<"This is a BMW car\n";
    }
};
class BenZ : public AbstractCar{
public:
    virtual void run(){
        cout<<"This is a BenZ car\n";
    }
};

class CarFactory{
public:
    static AbstractCar* GenerateCar(string car){
        if(car == "BMW")
            return new BMW;
        else if (car == "BenZ")
            return new BenZ;
        else
            return nullptr;
    }
};
int main(){
    CarFactory *factory = new CarFactory;
    AbstractCar* BMW = factory->GenerateCar("BMW");
    BMW->run();
    AbstractCar* BenZ = factory->GenerateCar("BenZ");
    BenZ->run();
}
