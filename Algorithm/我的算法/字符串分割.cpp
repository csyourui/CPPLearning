//
//  SplictString.cpp
//  Algorithms
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<string> Split(char *A, char *c){
    vector<string> res;
    char *token = strtok(A, c);
    while(token != NULL) {
        res.push_back(token);
        token = strtok(NULL, c);
    }
    return res;
}
vector<string> splictCString(string str, string c){
    vector<string> res;
    int pos1 = 0;
    int pos2 = (int) str.find(c);
    while(pos2!=str.npos){
        res.push_back(str.substr(pos1, pos2-pos1));
        pos1 = pos2 + (int)c.size();
        pos2 = (int)str.find(c, pos1);
    }
    if(pos1 != str.length()){
        res.push_back(str.substr(pos1));
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string str = ",,,a,b,c,ff,,d,f,s,";
    vector<string> res = splictCString((char *)str.c_str(), ",");
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
    cout << "Hello, World!\n";
    return 0;
}
