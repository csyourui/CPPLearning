//
//  UniString.cpp
//  test
//
//  Created by yourui on 2020/2/20.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(){
   string str = "";
   while (cin >> str) {
       map<char, int> myMap;
       for (int i = 0; i < str.length(); i++) {
           myMap[str[i]]++;
       }
       for (char a = 'a'; a <= 'z'; a++) {
           if(myMap[a])
               cout<<a<<myMap[a];
       }
       cout<<endl;
   }
}

