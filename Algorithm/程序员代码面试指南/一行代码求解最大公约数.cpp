//
//  一行代码求解最大公约数.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/20.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
using namespace std;
// m = n*q + r
// gcd(m, n) = gcd (n, r);
// 辗转相除法
int gcd(int m, int n){
    return n == 0 ? m : gcd(n, m%n);
}
int main(){
    cout<<gcd(100, 125)<<endl;
}

