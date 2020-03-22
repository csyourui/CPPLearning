//
//  ABCstr.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
__attribute((constructor))void before()
{
    printf("before main\n");
}
int main(){
    string str = "";
    while (cin >> str){
        int N = (int) str.length();
        cout<<(N+1)*26-N<<endl;
    }
}

