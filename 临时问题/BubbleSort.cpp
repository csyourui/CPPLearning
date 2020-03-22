//
//  BubbleSort.cpp
//  test
//
//  Created by yourui on 2020/2/23.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, i, j, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        for(j = 0; j < i; j++)
            if(a[j] > a[i])
                ans++;
    cout << ans << endl;
    return 0;
}
