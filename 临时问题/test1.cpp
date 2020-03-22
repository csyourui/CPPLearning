//
//  test1.cpp
//  test
//
//  Created by yourui on 2020/3/2.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int* duplication) {
    int *count = new int[length];
    for (int i = 0; i < length; i++) {
        count[i] = 0;
    }
    for(int i = 0;i < length; i++){
        if(count[numbers[i]] >= 1){
            *duplication = numbers[i];
            return true;
        }
        if(count[numbers[i]]==0) count[numbers[i]]++;
    }
    return false;
}
int main(){
    int a[] = {2,4,3,1,4};
    int duplication;
    bool ans = duplicate(a, 5, &duplication);
    cout<<ans<<" "<<duplication<<endl;
    return 0;
}
