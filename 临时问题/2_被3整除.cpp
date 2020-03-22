//
//  2_被3整除.cpp
//  LeetCode_Answer
//
//  Created by yourui on 2020/3/18.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
 并且小Q对于能否被3整除这个性质很感兴趣。
 小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
 */
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int l, r;
    while(cin >> l >> r) {
        int ans = 0;
        for(int i = l; i <= r; i++){
            int count = (1 + i) * i / 2;
            if( count % 3 == 0) ans++;
        }
        cout<<ans;
    }
}
