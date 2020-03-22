//
//  min(K).cpp
//  Algorithms
//
//  Created by yourui on 2020/3/19.
//  Copyright © 2020 yourui. All rights reserved.
//

class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void maxHeapify(vector<int> &v, int i, int n){
        int c1 = i * 2 + 1;
        int c2 = i * 2 + 2;
        while(c1 < n){
            int max = i;
            if(v[c1] > v[max]) max = c1;
            if(c2 < n && v[c2] > v[max]) max = c2;
            if(max == i) return;
            else{
                swap(v[max], v[i]);
                i = max;
                c1 = i * 2 + 1;
                c2 = i * 2 + 2;
            }
        }
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> minSet;
        if(input.size() < k || k <= 0) return minSet;
        for(int i = 0; i < k;i++){
            minSet.push_back(input[i]);
        }
        for(int i = k/2 - 1; i >=0; i--)
            maxHeapify(minSet, i, k);

        for(int i = k; i < input.size();i++){
            if(input[i] < minSet[0]){
                swap(input[i], minSet[0]);
                maxHeapify(minSet, 0, k);
            }
        }
        return minSet;
    }
};
