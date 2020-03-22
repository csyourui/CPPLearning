//
//  Pointer.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/3.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int i = 0;                  //定义了 非常量       i 并且初始化为 0
    cout<<"int i = 0;\t//定义了 非常量 i 并且初始化为 0: \n";

    int *p0 = &i;               //定义了 非常量整型指针 p0 指向非常量 i; 可以通过p0 修改i
    *p0 = *p0 + 1;
    cout<<*p0<<endl;
    
    int *const p1 = &i;         //定义了 常量整型指针 p1 指向非常量 i; 可以通过p1 修改i
    *p1 = *p1 + 1;
    cout<<*p1<<endl;

    int &r0 = i;                //定义了 非常量 i 的非常量整型引用 r0; 可以通过r0 修改i
    r0 = r0 + 1;
    cout<<r0<<endl;

    int const &r1 = i;          //定义了 非常量 i 的常量整型引用 r1;
    //r1 = r1 + 1;              //不可以通过r1 修改i ！！！！！！！
    cout<<r1<<endl;
    
    int ci = 1;           //定义了 常量ci,并且初始化为1
    cout<<"const int ci = 0;\t//定义了 常量ci,并且初始化为1\n";

    const int *p2 = &ci;        //定义了 非常量整型指针p2,指向常量ci
    //*p2 = *p2 + 1;
    cout<<*p2<<endl;
    const int *const p3 = &ci;  //定义了 常量整型指针p3,指向常量ci
    //*p3 = *p3 + 1;
    cout<<*p3<<endl;
    const int &r2 = ci;         //定义了 常量 i 的常量整型引用 r2
    //r2 = r2 + 1;              //变量是常量，引用默认都为常量引用 //const int "const"(可不要) &r3 = ci
    cout<<r2<<endl;
    
}
