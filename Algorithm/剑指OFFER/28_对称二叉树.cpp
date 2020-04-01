//
//  28_对称二叉树.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

bool isMirror(TreeNode* p1, TreeNode* p2){
    if(!p1 && !p2) return true;
    if(!p1 || !p2) return false;
    return p1->val == p2->val && isMirror(p1->left, p2->right) && isMirror(p1->right, p2->left);
}
bool isSymmetrical(TreeNode* pRoot)
{
    return isMirror(pRoot, pRoot);
}
