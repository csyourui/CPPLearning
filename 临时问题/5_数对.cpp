//
//  5_数对.cpp
//  LeetCode_Answer
//
//  Created by yourui on 2020/3/18.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long n, k;
    while(cin >> n >> k){
        long count = 0;
        if(k == 0){
            count = n*n;
        }
        else{
            for(int y = k + 1; y <= n; y++){
                count += (n / y) * (y - k);
                long temp = (n % y - k + 1);
                count += (temp>0)?temp:0;
            }
        }
        cout<<count<<endl;
    }
}
