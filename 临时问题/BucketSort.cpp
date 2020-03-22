//
//  BucketSort.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> stoInt(string str){
    vector<int> A;
    int left = 0, right = 0;
    while(right < str.length() && left <= right) {
        if(str[right] == ','){
            A.push_back(stoi(str.substr(left, right-left)));
            left = right + 1;
        }
        right++;
        if(right == str.length())
            A.push_back(stoi(str.substr(left)));
    }
    return A;
}
int main(){
    string str1 = "", str2 = "";
    while (cin >> str1){
        cin >> str2;
        string ansStr = "";
        vector<int> one = stoInt(str1);
        vector<int> two = stoInt(str2);
        vector<int> comb;
        int i = 0, j = 0;
        while( i < one.size() && j < two.size()){
            if(one[i] <= two[j]){
                comb.push_back(one[i++]);
            }
            else{
                comb.push_back(two[j++]);
            }
        }
        while (i < one.size()) {
            comb.push_back(one[i++]);
        }
        while (j < two.size()) {
            comb.push_back(two[j++]);
        }
        for (int i = 0; i < comb.size() - 1; i ++) {
            cout<<comb[i]<<",";
        }
        cout<<comb[comb.size() - 1]<<endl;
    }
}

