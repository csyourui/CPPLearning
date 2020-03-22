//
//  最长回文子串.cpp
//  test
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LPS(string str, int i, int j){
    while(i <= j && i >= 0 && j < (int)str.length() && str[i] == str[j]){
        i--;
        j++;
    }
    return j - i - 1;
}
int main(){
    vector<string> res;
    string str = "babada";
    int maxLen = 0;
    for (int i = 0; i < (int)str.length(); i++) {
        int len1 = LPS(str, i, i);
        int len2 = LPS(str, i, i + 1);
        if(len1)
            res.push_back(str.substr(i - len1 / 2, len1));
        if(len2)
            res.push_back(str.substr(i + 1 - len2 / 2, len2));
    }
    //排序
    sort(res.begin(), res.end());
    //去重
    res.erase(unique(res.begin(), res.end()), res.end());
    
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
}
