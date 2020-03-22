//
//  CatFood.cpp
//  test
//
//  Created by yourui on 2020/2/22.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int a, H, K, maxFoodPile = INT_MIN;
    vector<int> food;
    while(cin >> a) {
        maxFoodPile = max(maxFoodPile, a);
        food.push_back(a);
        if(getchar() == '\n')
            break;
    }
    cin >> H;
    int totolTime;
    for (K = 1; K <= maxFoodPile; K++) {
        totolTime = 0;
        for (int i = 0; i < food.size(); i++) {
            totolTime += ceil((double) food[i] / K);
        }
        if(totolTime <= H)
            break;
    }
    cout<<K<<endl;
}
