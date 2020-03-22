////
////  TwoStackQueue.cpp
////  C++Learning
////
////  Created by yourui on 2020/3/2.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//#include <stdio.h>
//#include <stack>
//using namespace std;
//
//class myQueue{
//public:
//    void push(int a){
//        stack1.push(a);
//    }
//    int pop(){
//        int a;
//        if(stack2.empty()){
//            while(!stack1.empty()){
//                int temp = stack1.top();
//                stack1.pop();
//                stack2.push(temp);
//            }
//        }
//        a = stack2.top();
//        stack2.pop();
//        return a;
//    }
//private:
//    stack<int> stack1;
//    stack<int> stack2;
//};
//
//int main(){
//    myQueue a;
//    a.push(1);
//    a.push(2);
//    a.push(3);
//    a.push(4);
//    a.push(5);
//    printf("%d\n", a.pop());
//    printf("%d\n", a.pop());
//    printf("%d\n", a.pop());
//    printf("%d\n", a.pop());
//    printf("%d\n", a.pop());
//}
