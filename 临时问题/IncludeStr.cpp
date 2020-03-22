//
//  IncludeStr.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

bool isInclude(string &A, string &B){
    int a =(int) A.length(),b = (int) B.length();
    if(a == 0 || b == 0) return false;
    if(a == b) return A == B;
    if(a < b) swap(A, B);
    int w = abs(a-b);
    for (int i = 0; i < w + 1; i++) {
        if(A.substr(i,min(a,b)) == B)
            return true;
    }
    return false;
}
int main(){
    string a, b;
    while(cin >> a >> b){
        int ans = isInclude(a, b);
        cout<<ans<<endl;
    }
}
