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

int main(){
   string str = "";
   cout<<"Print:\n";
   while (cin >> str){ 
       int N = (int) str.length();
       cout<<(N+1)*26-N<<endl;
   }
}

