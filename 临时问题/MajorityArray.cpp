//////
//////  MajorityArray.cpp
//////  test
//////
//////  Created by yourui on 2020/2/25.
//////  Copyright © 2020 yourui. All rights reserved.
//////
//
//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//vector<int> SplitArray(string str, char c){
//    vector<int> ar;
//    int pos2 = (int) str.find(c);
//    int pos1 = 0;
//    while(pos2 != str.npos){
//        ar.push_back(stoi(str.substr(pos1, pos2-pos1)));
//        pos1 = pos2 + 1;
//        pos2 = (int)str.find(',', pos1);
//    }
//    if(pos1 != str.length())
//        ar.push_back(stoi(str.substr(pos1)));
//    return ar;
//}
//
//int main(){
//    string str;
//    cin >> str;
//    vector<int> v = SplitArray(str, ',');
//    int N = (int) v.size();
//    map<int, int> myMap;
//    for (int i = 0; i < v.size(); i++) {
//        myMap[v[i]]++;
//        if(myMap[v[i]] > N / 2)
//            cout<<v[i]<<endl;
//    }
//}
