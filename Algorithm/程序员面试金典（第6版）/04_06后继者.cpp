//
//  04_06后继者.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/18.
//  Copyright © 2020 yourui. All rights reserved.
//

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(!root) return root;
    if(p->val >= root->val){
        return inorderSuccessor(root->right, p);
    }else{
        TreeNode* left = inorderSuccessor(root->left, p);
        return left?left:root;
    }
}
