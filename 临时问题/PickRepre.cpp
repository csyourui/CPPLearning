////
////  PickRepre.cpp
////  test
////
////  Created by yourui on 2020/2/23.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//#include <iostream>
//using namespace  std;
//
//struct Section{
//    int first;
//    int second;
//};
//bool cmp1(Section a, Section b){
//    return a.second < b.second;
//}
//int main(){
//    int N;
//    while( cin >> N){
//        Section *s = new Section[N];
//        for (int i = 0; i < N; i++) {
//            cin >> s[i].first >> s[i].second;
//        }
//        sort(s, s + N, cmp1);
//        int p1 = -1, p2 = -1, ans = 0;
//        for (int i = 0; i < N; i++) {
//            if(s[i].first > p1){
//                ans++;
//                p1 = p2;
//                p2 = s[i].second;
//            }
//            if(s[i].first > p1){
//                ans++;
//                p1 = s[i].second - 1;
//            }
//        }
//        cout<<ans<<endl;
//    }
//}
