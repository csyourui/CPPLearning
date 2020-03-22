////
////  Poster.cpp
////  test
////
////  Created by yourui on 2020/2/23.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//int main(){
//    int N;
//    while (cin >> N) {
//        int ans = 0;
//        vector<int> P(10000001,0);
//        int minV = INT_MAX, maxV = INT_MIN;
//        for (int i = 0; i < N; i++) {
//            int a,b;
//            cin >> a >> b;
//            minV = min(minV,min(a, b));
//            maxV = max(maxV,max(a, b));
//            for(int j = a; j <=b; j++)
//                P[j] = (i+1);
//        }
//        map<int,int> myMap;
//        for (int i = minV; i <= maxV; i++) {
//            if(myMap[P[i]]++ == 0 && P[i] != 0 )
//                ans++;
//        }
//        cout<<ans<<endl;
//    }
//}
