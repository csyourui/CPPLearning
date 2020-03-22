//
//  Bus.cpp
//  test
//
//  Created by yourui on 2020/2/25.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int memberCount, carCount;
    cin >> memberCount;
    cin >> carCount;
    
    int* members = new int[memberCount];

    for (int i = 0; i < memberCount; i++) {
        cin >> members[i];
    }
    
    vector<int> order;

    int carNumber = ceil((double) memberCount / carCount);
    vector<vector<int>> a(carNumber, vector<int>());
    for(int i = 0, j = 0; i < memberCount; i++){
        if(i % carCount==0 && i > 0)
            j++;
        a[j].push_back(members[i]);

    }
    for(int i = carNumber-1; i>=0; i--){
        for(int j = 0; j < a[i].size(); j++){
            order.push_back(a[i][j]);
        }
    }
    for (int i = 0; i < order.size(); i++) {
        cout<<order[i]<<" ";
    }
    cout<<endl;
    
}
