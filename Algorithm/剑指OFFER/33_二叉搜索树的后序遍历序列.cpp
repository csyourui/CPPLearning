//
//  34_二叉搜索树的后序遍历序列.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

bool help(vector<int> &v, int start, int end){
    if(start >= end) return true;
    int pivot = v[end], i = 0, j = end-1;
    while(j >=0 && v[j] > pivot) j--;
    while(i < v.size() && v[i] < pivot) i++;
    if(i < j) return false;
    return help(v, start, j) && help(v, j+1, end-1);
}
bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.size() == 0) return false;
    return help(sequence, 0, sequence.size()-1);
}
