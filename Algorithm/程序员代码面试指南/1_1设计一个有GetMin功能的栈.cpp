//
//  1_1设计一个有GetMin功能的栈.cpp
//  Main
//
//  Created by yourui on 2020/3/20.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <stack>
using namespace std;

class getMinStack{
private:
    stack<int> stackData;
    stack<int> stackMin;
public:
    void push(int a){
        stackData.push(a);
        if(stackMin.empty() || a <= stackMin.top())
            stackMin.push(a);
    }
    int pop(){
        if(stackData.empty()) return -1;
        int value = stackData.top();
        stackData.pop();
        if(value == stackMin.top()) stackMin.pop();
        return value;
    }
    int getMin(){
        return stackMin.top();
    }
};
int main(){
    getMinStack myStack;
    myStack.push(1);//1
    myStack.push(5);//1 5
    myStack.push(3);//1 5 3
    myStack.push(0);//1 5 3 0
    printf("%d\n", myStack.getMin());
}
