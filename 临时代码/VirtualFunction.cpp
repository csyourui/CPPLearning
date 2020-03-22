//
//  VirtualFunction.cpp
//  test
//
//  Created by yourui on 2020/3/1.
//  Copyright © 2020 yourui. All rights reserved.
//

#include<iostream>
using namespace std;
class A
{
    public:
        virtual void print()
        {
            cout<<"This is A"<<endl;
        }
};
 
class B : public A
{
    public:
        void print()
        {
            cout<<"This is B"<<endl;
        }
};
 
//int main()
//{
//    //为了在以后便于区分，我这段main()代码叫做main1
//    A a;
//    B b;
//    a.print();
//    b.print();
//    return 0;
//}

int main()
{
    //main2
    A a;
    B b;
    A *p1 = &a;
    A *p2 = &b;
    p1->print();
    p2->print();
    return 0;
}
