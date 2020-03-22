//
//  Candy.cpp
//  test
//
//  Created by yourui on 2020/2/22.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> g;
    vector<int> s;
    int temp, ans = 0;
    while( cin >> temp){
        g.push_back(temp);
        if(getchar() == '\n')
            break;
    }
    while( cin >> temp){
        s.push_back(temp);
        if(getchar() == '\n')
            break;
    }
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gIndex = 0, sIndex = 0;
    while (gIndex < g.size() && sIndex < s.size()) {
        if(s[sIndex] >= g[gIndex]){
            gIndex++;
            sIndex++;
            ans++;
        }
        else{
            sIndex++;
        }
    }
    cout<<ans<<endl;
}
