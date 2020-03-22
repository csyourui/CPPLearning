//
//  Jinzhi.cpp
//  test
//
//  Created by yourui on 2020/2/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
using namespace std;

int main (){
    long x, k;
    while (cin >> x >> k){
        string ans = "";
        while(x){
            long p = x % k;
            ans.insert(ans.begin(), p + '0');
            x /= k;
        }
        cout<<ans<<endl;
    }
}
