//
//  MyString.h
//  C++Learning
//
//  Created by yourui on 2020/4/16.
//  Copyright © 2020 yourui. All rights reserved.
//

#ifndef MyString_h
#define MyString_h
#include <string.h>
#include <iostream>
using namespace std;

class MyString{
public:
    MyString();                                     //构造函数
    MyString(const char*);                          //有参构造
    MyString(const MyString& );                     //拷贝构造函数
    MyString& operator =(const MyString &);         //拷贝赋值运算符
    MyString operator +(const MyString &);          //重载加法运算符
    char &operator[](int i);                        //重载方括号运算符
    size_t length();
    ~MyString();                                    //析构函数
private:
    char *data;
    size_t len;
};
MyString::MyString(){
    len = 0;
    //data = NULL
    data = new char[1];
    data[0] = '\0';
}
MyString::MyString(const char* str){
    if(str == NULL){
        len = 0;
        data = new char[1];
        data[0] = '\0';
    }else{
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }
}

MyString::MyString(const MyString& str){
    len = str.len;
    data = new char[len + 1];
    strcpy(data, str.data);
}
MyString& MyString::operator =(const MyString &str){
    if(this == &str)
        return *this;
    delete []data;
    len = str.len;
    data = new char[len + 1];
    strcpy(data, str.data);
    return *this;
}
MyString MyString::operator +(const MyString &str){
    MyString temp;
    temp.len = this->len + str.len;;
    temp.data = new char[temp.len + 1];
    memset(temp.data, 0, len + 1);
    strcpy(temp.data, this->data);
    strcat(temp.data, str.data);
    return temp;
}
char& MyString::operator[](int i){
    return *(data + i);
}
size_t MyString::length(){
    return len;
}
MyString::~MyString(){
    delete []data;
}

#endif /* MyString_h */
