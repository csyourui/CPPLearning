//
//  字符串分割.cpp
//  C++Learning
//
//  Created by yourui on 2020/8/26.
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
vector<string> splitString(string str, string c, bool zero = true) {
  vector<string> v;
  int pos1 = 0, pos2 = str.find(c, pos1);
  while (pos2 != str.npos) {
    if (zero || pos2 != pos1) {
      v.push_back(str.substr(pos1, pos2 - pos1));
    }
    pos1 = pos2 + c.size();
    pos2 = str.find(c, pos1);
  }
  if (pos1 != str.size()) {
    v.push_back(str.substr(pos1));
  }
  return v;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string str = ",,,a,b,c,ff,,d,f,s,";
    vector<string> res = splitString((char *)str.c_str(), ",");
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
    cout << "Hello, World!\n";
    return 0;
}
