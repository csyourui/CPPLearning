//
//  9_两个栈实现队列.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

class Solution
{
public:
    void push(int a){
        S1.push(a);
    }
    int pop(){
        if(S2.empty()){
            while(!S1.empty()){
                int temp = S1.top();
                S1.pop();
                S2.push(temp);
            }
        }
        int temp = S2.top();
        S2.pop();
        return temp;
    }
private:
    stack<int> S1;
    stack<int> S2;
};
