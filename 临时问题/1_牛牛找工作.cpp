//
//  1_牛牛找工作.cpp
//  LeetCode_Answer
//
//  Created by yourui on 2020/3/18.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 
 输入描述：
 *****************************************************************
 *每个输入包含一个测试用例。
 *每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
 *接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
 *接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
 *保证不存在两项工作的报酬相同。
 *****************************************************************
 输出描述：
 *****************************************************************
 *****************************************************************
 
 */
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<pair<int, int> > job(n + 1), guy(m);
        vector<int> map(m);
        int mx = 0, index = 0, left = 0;
        job[0] = make_pair(0, 0);
        for(int i = 1; i <= n; ++ i) {
            cin >> job[i].first >> job[i].second;
        }
        for(int i = 0; i < m; ++ i) {
            cin >> guy[i].first;
            guy[i].second = i;
        }
        sort(job.begin(), job.end(), [&](pair<int, int> a, pair<int, int> b){return a.first < b.first;});
        sort(guy.begin(), guy.end(), [&](pair<int, int> a, pair<int, int> b){return a.first < b.first;});
        for(int i = 0; i <= n; ++ i) {
            mx = max(mx, job[i].second);
            job[i].second = mx;
        }
        while(left < m && index < n + 1) {
            if(guy[left].first >= job[index].first) ++ index;
            else {
                map[guy[left].second] = job[index - 1].second;
                ++ left;
            }
        }
        for(int i = left; i < m; ++ i) {
            map[guy[i].second] = job[n].second;
        }
        for(int i = 0; i < m; ++ i) {
            cout << map[i] << endl;
        }
    }
}
