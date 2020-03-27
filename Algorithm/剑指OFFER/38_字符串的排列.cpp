//
//  38_字符串的排列.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

void backtrack(vector<string> &ansSet, vector<bool> isVisited, string tempStr, const string &str)
{
    if(tempStr.length() == str.length()){
        if(find(ansSet.begin(), ansSet.end(), tempStr) == ansSet.end())
            ansSet.push_back(tempStr);
        return;
    }
    for(int i = 0; i < str.length(); i++){
        if(!isVisited[i]){
            isVisited[i] = true;
            backtrack(ansSet, isVisited, tempStr+str[i], str);
            isVisited[i] = false;
        }
    }
    return;
}
vector<string> Permutation(string str) {
    vector<string> ansSet;
    int N = str.length();
    if(N==0) return ansSet;
    sort(str.begin(), str.end());
    vector<bool> isVisited(N);
    backtrack(ansSet, isVisited, "", str);
    return ansSet;
}
