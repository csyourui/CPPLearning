//
//  SplictString.cpp
//  Algorithms
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<string> splictString(string str){
    vector<string> res;
    int pos1 = 0;
    int pos2 = (int) str.find(',');
    while(pos2!=str.npos){
        if(pos2!=pos1)
            res.push_back(str.substr(pos1, pos2-pos1));
        pos1 = pos2 + 1;
        pos2 = (int)str.find(',', pos1);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> res = splictString(",,,a,b,c,ff,,d,f,s,");
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
    cout << "Hello, World!\n";
    return 0;
}
