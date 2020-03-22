//
//  二叉树最远节点的距离.c
//  test
//
//  Created by yourui on 2020/3/11.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include "../C++Learning/TreeNode.h"
using std::max;
int maxPath(TreeNode *root, int &maxLen){
    if (!root) {
        return 0;
    }
    int left = maxPath(root->left, maxLen);
    int right = maxPath(root->right, maxLen);
    maxLen = max(maxLen, left + right);
    return max(left, right) + 1;
}


int main(){
    return 0;
}
