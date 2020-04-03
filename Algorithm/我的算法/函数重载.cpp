//
//  函数重载.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/1.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 赋值（=），下标（[]），调用（()）和成员访问箭头（->）运算符必须是成员、
 复合赋值运算符一般来说应该是成员，但并非必须，这一点与赋值运算符略有不同。
 改变对象状态的运算符符或者与给定类型密切相关的运算符，如递增，递减和解引用运算符，通常应该是成员。
 具有对称性的运算符可能转换任意一端的运算对象，例如算术，相等性，关系和位运算符等，因此他们通常应该是普通的非成员函数。
 
 
 
 */
#include <iostream>
using namespace std;

class Point{
public:
    Point(int x = 0, int y = 0):x(x), y(y){}
    Point& operator+(Point &p);
    Point& operator-(Point &p);
    
    Point* operator&();
    const Point* operator&() const;
    
    Point& operator++();
    Point operator++(int);
    int &operator[](int);

    ~Point(){}
//private:
public:
    int x;
    int y;

};

// +操作符
Point& Point::operator+(Point &p){
    Point *temp = new Point(x + p.x, y + p.y);
    return *temp;
}

// -操作符
Point& Point::operator-(Point &p){
    Point *temp = new Point(x - p.x, y - p.y);
    return *temp;
}
//++Point
Point& Point::operator++(){
    x += 1;
    y += 1;
    return *this;
}
//Point++
Point Point::operator++(int){
    Point P = *this;
    ++(*this);
    return P;
}
//&
Point* Point::operator&(){
    return this;
}
const Point* Point::operator&() const{
    return this;
}
//输出
ostream& operator<<(ostream& out, Point& p1){
    out << "a = "<< p1.x << "\tb = " << p1.y;
    return out;
}
//输入
istream& operator>>(istream& in, Point& p1){
    in >> p1.x >> p1.y;
    return in;
}

int& Point::operator[](int i){
    if(i == 1) return x;
    if(i == 2) return y;
    return x;
}

int main()
{
    Point a(1, 2), b(3, 4), c(4, 5);
    Point d = a - b + c;
    cout << &d <<endl;
    cout << a <<endl;
    cout<< b[1]<<endl;
    // 运算符重载的本质 是函数调用
    return 0;
}

