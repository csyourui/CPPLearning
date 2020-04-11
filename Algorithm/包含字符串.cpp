//
//  包含字符串.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/10.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


int minLength(string str1, string str2){
    if(str1 == "" || str2 =="" || str1.length() < str2.length()){
        return 0;
    }
    int map[256] = {0};
    for (int i = 0; i< str2.length(); i++){
        map[str2[i]]++;
    }
    int left= 0;
    int right = 0;
    int minLen = INT_MAX;
    int match = (int)str2.length();
    while (right != str1.length()){
        map[str1[right]]--;
        if(map[str1[right]] >= 0){
            match--;
        }
        if(match == 0){
            while (map[str1[left]] < 0){
                map[str1[left++]]++;
            }
            minLen = min(minLen, right - left + 1);
            match++;
            map[str1[left++]]++;
        }
        right++;
    }
    return minLen;
}


int main(){
    string str1 = "abcde";
    string str2 = "ac";
    cout<<minLength(str1, str2)<<endl;
}


