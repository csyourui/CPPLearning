//
//  1_2两个栈组成队列.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/20.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include <stack>
using namespace std;

class myQueue{
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    void push(int a){
        stack1.push(a);
    }
    int pop(){
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int val = stack2.top();
        stack2.pop();
        return val;
    }
};
int main(){
    myQueue queue;
    queue.push(1);//1
    queue.push(5);//1 5
    queue.push(3);//1 5 3
    //queue.push(0);//1 5 3 0
    cout<<"Dsdadsdas\n";
    cout<<queue.pop()<<endl;
}

