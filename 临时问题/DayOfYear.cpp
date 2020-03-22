////
////  DayOfYear.cpp
////  test
////
////  Created by yourui on 2020/2/21.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//#include <iostream>
//
//using namespace std;
//int dayOfMon[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
//bool isLeapYear(int Year){
//    return ((Year % 4 == 0) && (Year % 100 !=0))||((Year % 400 ==0));
//}
//
//int main(){
//    int Year, Month, Day;
//    int accsum[13] = {0};
//    for (int i = 1; i < 13; i++) {
//        accsum[i] = accsum[i-1] + dayOfMon[i];
//    }
//
//    while (cin >> Year >> Month >> Day) {
//        int ans = Day + accsum[Month - 1] + (isLeapYear(Year) && Month > 2);
//        cout<<ans<<endl;
//    }
//}
