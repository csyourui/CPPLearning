//
//  NumberOfOne.cpp
//  test
//
//  Created by yourui on 2020/2/29.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
using namespace std;
double Power(double base, int exponent) {
    double ans = 1.0;
    while(exponent--){
        ans *= base;
    }
    return ans;x
}
int NumberOf1(int n) {
    int ans = 0;
    if(n < 0){
        ans++;
        n = -n;
    }
    while(n){
        if(n&1) ans++;
        n = n >> 1;
    }
    return ans;
}

int main(){
    double a;
    int b;
    while (cin >> a >> b) {
        cout<<Power(a, b)<<endl;
    }
}
