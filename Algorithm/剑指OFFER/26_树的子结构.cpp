//
//  26_树的子结构.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

bool isSame(TreeNode* a, TreeNode* b){
    if (!b) return true;
    if (!a) return false;
    if (a->val != b->val) return false;
    return isSame(a->left, b->left) && isSame(a->right, b->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(!pRoot1 || !pRoot2) return false;
    return isSame(pRoot1, pRoot2)||\
        HasSubtree(pRoot1->left, pRoot2) || \
        HasSubtree(pRoot1->right, pRoot2);
}
