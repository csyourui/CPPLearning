//
//  OrderStr.cpp
//  test
//
//  Created by yourui on 2020/2/20.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
   int M;
   while (cin >> M) {
       vector<string> strList(M);
       vector<int> A;
       for (int i = 0; i < M; i++) {
           cin >> strList[i];
       }
       for (int i = 0; i < M; i++) {
           A.push_back(stoi(strList[i].substr(strList[i].length()-6)));
       }
       sort(A.begin(), A.end());
       for (int i = 0; i < A.size(); i++) {
           cout<<A[i]<<endl;
       }
   }
}

