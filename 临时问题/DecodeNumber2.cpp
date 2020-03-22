//
//  DecodeNumber2.cpp
//  test
//
//  Created by yourui on 2020/2/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void help(int i, string ans ,string str, vector<string> &ansSet){
    if(i==str.length()) {
        ansSet.push_back(ans);
        return;
    }
    char c = str[i]-'1'+'a';
    if(str[i]!='0')
        help(i + 1, ans+c, str, ansSet);
    if(i + 1 < str.length()){
        int temp = (str[i] - '0') * 10 + (str[i+1] - '0');
        if(temp >= 10 && temp <= 26){
            char c = temp-1 + 'a';
            help(i + 2, ans+c, str, ansSet);
        }
    }
}
int main(){
    string str;
    while(cin >> str){
        vector<string> ansSet;
        help(0, "", str,ansSet);
        for (int i = 0; i < ansSet.size(); i++) {
            cout<<ansSet[i];
            if(i != ansSet.size() - 1)
                cout<<" ";
        }
        cout<<endl;
    }
}

//igfctdgahbihee igfctdgrbihee
