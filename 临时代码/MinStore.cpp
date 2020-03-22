//
//  MinStore.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#define N 10000
using namespace std;

int main(){
   int X;
   while(cin >> X){
       int dp[N+1]={0};
       dp[0] = 0;
       for(int i = 1; i <= X; i++){
           int temp = INT_MAX;
           for(int j = 3; j <= 7 && j <= i; j = j +2){
               if(dp[i - j] != -1)
                   temp = min(temp, dp[i - j] + 1);
           }
           dp[i] = (temp == INT_MAX) ? -1 : temp;
       }
       for (int i = 1; i <= X; i++) {
           cout<<i<<": "<<dp[i]<<endl;
       }
   }
}
