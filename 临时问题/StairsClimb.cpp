//
//  StairsClimb.cpp
//  test
//
//  Created by yourui on 2020/2/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string sum(string a, string b){
    string ans = "";
    int i = (int)a.length() - 1, j = (int)b.length() - 1;
    int carry = 0;
    while(i>=0 || j>=0 || carry){
        int x = (i>=0)?(a[i]-'0'):(0);
        int y = (j>=0)?(b[j]-'0'):(0);
        int p = x + y + carry;
        carry = p / 10;
        ans.insert(ans.begin(), (p % 10) + '0');
        i--;
        j--;
    }
    if(carry)
        ans.insert(ans.begin(), carry + '0');
    return ans;
}
int main(){
    int n;
    while(cin >> n){
        vector<string> dp(n+1);
        dp[0] = "1";
        dp[1] = "1";
        for(int i = 2; i <= n; i++){
            dp[i] = sum(dp[i-1], dp[i-2]);
        }
        cout<<dp[n]<<endl;
    }
}
