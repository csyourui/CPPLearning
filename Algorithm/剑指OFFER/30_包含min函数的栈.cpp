//
//  30_包含min函数的栈.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

class Solution {
public:
    void push(int value) {
        dataStack.push(value);
        minStack.push(minStack.empty()?value:std::min(value, minStack.top()));
    }
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    int top() {
        return dataStack.top();
    }
    int min() {
        return minStack.top();
    }
private:
    stack<int> dataStack;
    stack<int> minStack;
};
