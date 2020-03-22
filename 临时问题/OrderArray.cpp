//
//  OrderArray.cpp
//  test
//
//  Created by yourui on 2020/2/21.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int i, left, right;
        for(i = 0; i < sqrt(2*n+1); i++){
            left = (1+i)*i/2;
            right = (1+i+1)*(i+1)/2;
            if( n > left && n <= right )
                break;
        }
        cout<<i+1<<endl;
    }
}
