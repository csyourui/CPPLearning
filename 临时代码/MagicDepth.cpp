//
//  MagicDepth.cpp
//  test
//
//  Created by yourui on 2020/2/20.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAXDEPTH 1000
#define MODVAL 1000000003
int main(){
   int M;
   vector<int> dp(MAXDEPTH + 1, 0);
   dp[0] = 1;
   for (int i = 1; i <= MAXDEPTH; i++) {
       int a = log(i) / log(2);
       for (int j = 0; j <= a; j++) {
           dp[i] += ((dp[i - (int) pow(2,j)]) % MODVAL);
           dp[i] %= MODVAL;
       }
       dp[i] %= MODVAL;
   }
   while (cin >> M) {
       vector<int> Dep(M);
       for (int i = 0; i < M; i++) {
           cin >> Dep[i];
       }
       
       for (int i = 0; i < M; i++) {
           cout << dp[Dep[i]] <<endl;
       }
   }
   return 0;
}
