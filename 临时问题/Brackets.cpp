//
//  Brackets.cpp
//  test
//
//  Created by yourui on 2020/2/23.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    while (cin >> str) {
        int N = (int)str.length();
        stack<char> myStack;
        string flag = "true";
        for (int i = 0; i < N; i++) {
            if(str[i]=='(' || str[i] == '[')
                myStack.push(str[i]);
            if (str[i] == ']') {
                if(myStack.top() == '[')
                   myStack.pop();
                else{
                    flag = "false";
                    break;
                }
            }
            if (str[i] == ')') {
                if(myStack.top() == '(')
                   myStack.pop();
                else{
                    flag = "false";
                    break;
                }
            }
        }
        cout<<flag<<endl;
    }
}
