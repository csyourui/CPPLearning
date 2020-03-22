
//  ThirdNumber.cpp
//  test
//
//  Created by yourui on 2020/2/25.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> SplitArray(string a){
    string str = a.substr(1,a.length()-2);
    vector<int> ar;
    int pos2 = (int) str.find(',');
    int pos1 = 0;
    while(pos2 != str.npos){
        ar.push_back(stoi(str.substr(pos1, pos2-pos1)));
        pos1 = pos2 + 1;
        pos2 = (int)str.find(',', pos1);
    }
    if(pos1 != str.length())
        ar.push_back(stoi(str.substr(pos1)));
    return ar;
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    string str;
    while(cin >> str){
        vector<int> v = SplitArray(str);
        int N =(int) v.size();
        for(int i = 0; i < 3;i++){
            for(int j = 0;j < N - i - 1;j++){
                if(v[j]>v[j+1])
                    swap(v[j], v[j+1]);
            }
        }
        cout<<v[N-3]<<endl;
        for (int i = 0; i < N; i++) {
            cout<<v[i]<<endl;
        }
    }
    
}
