//
//  AddSub.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str = "";
    while (cin >> str){
        int ans = 0;
        for (int i = 0; i < str.length();) {
            char c = str[i];
            if(c == '-'||c == '+') i++;
            
            int temp = 0;
            while (i < str.length() && str[i] != '-' && str[i] != '+') {
                temp = 10 * temp + (str[i] - '0');
                i++;
            }
            if(c == '-') ans -= temp;
            else ans += temp;
        }
        cout<<ans<<endl;
    }
}
