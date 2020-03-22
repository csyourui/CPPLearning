//
//  Str.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/3.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void count_calls(){
    static int ctr = 1;
    cout<<"第"<< ctr++ <<"次调用"<<endl;
}
int main(){

    for(int i = 0; i < 10; i++){
        count_calls();
    }
}
