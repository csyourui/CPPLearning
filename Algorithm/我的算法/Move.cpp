//
//  Move.cpp
//  test
//
//  Created by yourui on 2020/3/10.
//  Copyright © 2020 yourui. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str = "Hello";
    vector<string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    cout << "After copy, str is \"" << str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(move(str));
    cout << "After move, str is \"" << str << "\"\n";
    cout << "The contents of the vector are \"" << v[0]<< "\", \"" << v[1] << "\"\n";
}
