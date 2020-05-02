//
//  01_01判定字符是否唯一.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/18.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
 */
bool isUnique(string s) {
    int bucket[256] = {0};
    for(int i = 0; i < (int)s.length(); i++){
        int c = s[i];
        if(bucket[c] > 0){
            return false;
        }
        bucket[c] = 1;
    }
    return true;
}
