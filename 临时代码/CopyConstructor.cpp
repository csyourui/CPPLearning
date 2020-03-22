////
////  CopyConstructor.cpp
////  test
////
////  Created by yourui on 2020/3/1.
////  Copyright © 2020 yourui. All rights reserved.
////
//#include <iostream>
//using namespace std;
//
//class Point
//{
//    public:
//    Point(int xx=0,int yy=0)   //定义构造函数
//    {
//        X=xx;
//        Y=yy;
//    }
//    Point(const Point &p);                    //声明默认拷贝构造函数
//    int GetX()  {
//        return X;
//    }
//    int GetY()  {
//        return Y;
//        
//    }
//    private:
//    int X,Y;
//};
//
//Point::Point (const Point &p)//定义拷贝构造函数
//{
//    X = p.X;
//    Y = p.Y;
//    cout<<"拷贝构造函数被调用"<<endl;
//}
//int main(){
//    Point A(1,2);
//    Point B(A);
//    //B = A;
//    cout<<B.GetX()<<" "<<B.GetY()<<endl;
//}
