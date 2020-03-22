//
//  Latex.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
   int N, P, H, W;
   //N个段落
   //不多于P页
   //高度H
   //宽度WW
   //1 10 4 3
   //10
   //3
   while (cin >> N >> P >> H >> W) {
       vector<int> A(N);
       for (int i = 0; i < N; i++) {
           cin >> A[i];
       }
       int S, rowNum, colNum, maxRow;
       for (S = min(H, W); S >=1 ; S--) {
           colNum = W / S;
           rowNum = H / S;
           maxRow = rowNum * P;
           int totalRow = 0;
           for (int i = 0; i < N; i++) {
               totalRow += ceil((double)A[i] / colNum);
           }
           if (totalRow <= maxRow) {
               break;
           }
       }
       cout<<S<<endl;
   }
}
//
