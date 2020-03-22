//
//  Boat.cpp
//  test
//
//  Created by yourui on 2020/2/23.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main(){
    string str;
    vector<int> people;
    int x, limit, sumOfWeight = 0;
    getline(cin, str);
    stringstream ss(str);
    while(ss>>x)
    {
        people.push_back(x);
        sumOfWeight += x;
    }
    cin >> limit;
    int N = (int) people.size();
    vector<int> A(N,1);
    sort(people.begin(), people.end());
    int numOfPeople = 0, numOfBoat = 0;
    for (int i = N - 1; i >= 0; i--) {
        if(!A[i])
            continue;
        numOfBoat++;
        int tempLimit = limit;
        for (int j = i; j >= 0; j--) {
            if(people[j] <= tempLimit && A[j]){
                tempLimit -= people[j];
                A[j] = 0;
            }
        }
    }
    cout<<numOfBoat<<endl;
}
