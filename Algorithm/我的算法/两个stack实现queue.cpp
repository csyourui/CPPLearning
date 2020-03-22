//
//  两个stack实现queue.cpp
//  test
//
//  Created by yourui on 2020/3/10.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class myQueue{
public:
    void push(int n){
        stack1.push(n);
    }
    
    int pop(){
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    myQueue q;
    q.push(1);
    q.push(3);
    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    q.push(7);
    cout<<q.pop()<<endl;
    q.push(9);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

}

