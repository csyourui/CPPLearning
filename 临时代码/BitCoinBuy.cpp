//
//  BitCoinBuy.cpp
//  test
//
//  Created by yourui on 2020/2/22.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
   vector<int> Val;
   int a;
   while(cin >> a){
       Val.push_back(a);
   }
   int buy = 0, sell = 0, maxVal = 0;
   for(int i = 1;i < Val.size(); i++){
       if(Val[i] <= Val[i-1])
           continue;
       else{
           buy = i - 1;
           for(int j = i; j < Val.size(); j++){
               maxVal = max(maxVal, Val[j]-Val[i-1]);
           }
       }
   }
   cout<<maxVal<<endl;
}
