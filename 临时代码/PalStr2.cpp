//
//  PalStr2.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void find(int &count,string str, int i, int j){
   while(i>=0 && j <str.length() && str[i] == str[j]){
       count++;
       i--;
       j++;
   }
}
int main(){
   string str = "";
   while (cin >> str){
       int count = 0;
       for (int i = 0; i < str.length(); i++) {
           find(count, str, i, i);
           find(count, str, i, i + 1);
       }
       cout<<count;
   }
}
