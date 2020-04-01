//
//  31_栈的压入、弹出序列.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//
// pushV = {1,2,3,4,5};
// popV = {4,5,3,2,1};
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> S;
    int N = pushV.size();
    for(int i = 0, j = 0; i < N; i++){
        S.push(pushV[i]);
        while(i < N && !S.empty() && S.top() == popV[j]){
            S.pop();
            j++;
        }
    }
    return S.empty();
}
