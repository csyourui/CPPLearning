//
//  AddNo.cpp
//  test
//
//  Created by yourui on 2020/3/2.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
using namespace std;
 int Add(int num1,int num2) {
     int sum = num1 ^ num2;
     int carry = (num1 & num2) << 1;
     if(!carry) return sum;
     else return Add(sum, carry);
 }

int main(){
    int a = 2, b = 3;
    cout<<Add(a, b)<<endl;
}
