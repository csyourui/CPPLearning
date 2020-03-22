//
//  ArrayJump.cpp
//  test
//
//  Created by yourui on 2020/2/25.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    string a;
    while(cin >> a){
        int length =(int) a.length();
        string str = a.substr(1,length-2);
        vector<int> ar;
        int pos2 = (int) str.find(',');
        int pos1 = 0;
        while(pos2 != str.npos){
            ar.push_back(stoi(str.substr(pos1, pos2-pos1)));
            pos1 = pos2 + 1;
            pos2 = (int)str.find(',', pos1);
        }
        if(pos1 != str.length())
            ar.push_back(stoi(str.substr(pos1)));

        int N = (int)ar.size();
        vector<bool> visited(N, false);
        int i = 0;
        string ans = "true";
        while(i >= 0 && i < N){
            if(visited[i]){
                ans = "false";
                break;
            }
            else
                visited[i] = true;
            i = i + ar[i];
        }
        cout<<ans<<endl;
    }
}
