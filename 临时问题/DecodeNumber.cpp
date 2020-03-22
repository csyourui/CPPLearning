//
//  DecodeNumber.cpp
//  test
//
//  Created by yourui on 2020/2/23.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string str;
    while (cin >> str){
        int N = (int)str.length();
        vector<int> dp(N+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= N; i++){
            int temp = (str[i-1] - '0') + 10 * (str[i-2] - '0');
            if(temp >= 10 && temp <=26){
                dp[i] = dp[i-1] + dp[i-2];
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        cout<<dp[N]<<endl;
    }
}
