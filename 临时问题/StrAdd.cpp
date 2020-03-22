////
////  StrAdd.cpp
////  test
////
////  Created by yourui on 2020/2/24.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//string add(string a, string b){
//    string ans;
//    int an = (int)a.length(), bn = (int)b.length();
//    int i = an - 1, j = bn - 1, carry = 0;
//    while( i >= 0 || j >= 0||carry){
//        int sum = (i >= 0 ?a[i] - '0':0)+(j >=0 ?b[j] - '0':0)+carry;
//        carry = sum / 2;
//        sum = sum % 2;
//        ans.insert(ans.begin(),sum+'0');
//        i = i >= 0 ? i - 1 : i;
//        j = j >= 0 ? j - 1 : j;
//    }
//    return ans;
//}
//int main(){
//    string a, b;
//    while(cin >> a >> b){
//        cout<<add(a, b)<<endl;
//    }
//}
