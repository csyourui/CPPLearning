//
//  27_二叉树的镜像.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 
 二叉树的镜像定义：源二叉树
     8
    /  \
   6   10
  / \  / \
 5  7 9  11
 镜像二叉树
     8
    /  \
   10   6
  / \  / \
 11  9 7  5
 */
void Mirror(TreeNode *pRoot) {
    if(!pRoot) return;
    //交换某个节点的左右子树
    TreeNode *temp = pRoot->left;
    pRoot->left  = pRoot -> right;
    pRoot->right = temp;
    //若是左子树不为空，则递归地调用左子树
    //若是右子树不为空，则递归地调用右子树
    if(pRoot->left) Mirror(pRoot->left);
    if(pRoot->right) Mirror(pRoot->right);
}
