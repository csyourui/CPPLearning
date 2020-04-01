//
//  汉诺塔(递归).cpp
//  C++Learning
//
//  Created by yourui on 2020/3/31.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
using namespace std;

void Hanoti(int n, string start, string temp, string end){
    if(n == 1){
        cout<<start<<"->"<<end<<endl;
    }else{
        Hanoti(n-1, start, end, temp);
        Hanoti(1, start, temp, end);
        Hanoti(n-1, temp, start, end);
    }
}

int main(){
    Hanoti(3, "A", "B", "C");
}
