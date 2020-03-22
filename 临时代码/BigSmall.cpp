//
//  BigSmall.cpp
//  main
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
using namespace std;
union U
{
    int a;
    char b;
};
int main()
{
//    char a[] = "ABCD";
//    int *p = (int*)a;
//    cout<<*p<<endl;
    //16进制中 a的内存为     41 42 43 44
    //按小端端模式读取       0x 44 43 42 41 = 1145258561
    //高位地址存在高位
    U u;
    u.a = 0x41424344; // ABCD
    cout<<u.b<<endl;

    if (u.b == 0x44) {
        cout<<"小端"<<endl;
    }
    else if(u.b == 0x41){
        cout<<"大端"<<endl;
    }
    return 0;
}
