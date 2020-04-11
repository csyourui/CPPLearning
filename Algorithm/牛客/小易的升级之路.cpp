//
//  小易的升级之路.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/9.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&tqId=29329&tPage=4&rp=4&ru=/ta/2016test&qru=/ta/2016test/question-ranking
*/


#include <iostream>
#include <vector>
using namespace std;

// m = n*r+a-> gcd(m,n) = gcd(n, a)
/*
 3 50
 50 105 200
 5 20
 30 20 15 40 100
 */
int gcd(int m, int n){
    return n == 0 ? m : gcd(n, m % n);
}
int main(){
    int n, a, tmp;
    while(scanf("%d %d", &n, &a)){
        for(int i = 0; i < n; i++){
            scanf("%d",&tmp);
            if(tmp <= a){
                a += tmp;
            }
            else{
                a += gcd(tmp, a);
            }
        }
        printf("%d\n", a);
    }
}
