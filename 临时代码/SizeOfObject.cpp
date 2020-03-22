//
//  SizeOfObject.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/7.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
using namespace std;
 
class A {
public:
    A(int x=0) {
        cout<<"A: "<<x<<endl;
    }
    virtual void print() {
        cout<<"Hello A\n";
    }
};
class B {
public:
    B(int x=0) {
        cout<<"B: "<<x<<endl;
    }
    virtual void print() {
        cout<<"Hello B\n";
    }
};
 
class C : public B, public A{
public:
    C() {
        cout<<"C: "<<endl;
    }
    virtual void print() {
        cout<<"Hello C\n";
    }
};
 
int main() {
    A *a;
    a = new C;
    cout<<"size of a:"<<sizeof(a)<<endl;
    //cout<<"size of b:"<<sizeof(b)<<endl;
    //cout<<"size of c:"<<sizeof(c)<<endl;
    a->print();
    //b.print();
    //c.print();
    return 0;
}
