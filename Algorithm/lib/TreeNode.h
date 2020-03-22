//
//  TreeNode.h
//  C++Learning
//
//  Created by yourui on 2020/3/10.
//  Copyright © 2020 yourui. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h
#include <vector>
template<class T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
    static TreeNode<T>* PreAndIn(std::vector<T> pre, int pStart, int pEnd, std::vector<T> vin, int inStart, int inEnd);
    static TreeNode<T>* BacAndIn(std::vector<T> bac, int bStart, int bEnd, std::vector<T> vin, int inStart, int inEnd);
    int heightOfTree(TreeNode<T> *root);
    bool isBST(TreeNode<T> *root);
    
};
/*
 前序和中序遍历重建树
 */
template<class T>
static TreeNode<T>* PreAndIn(std::vector<T> pre, int pStart, int pEnd, std::vector<T> vin, int inStart, int inEnd){
    if(pStart > pEnd || inStart > inEnd)//首位超界
        return nullptr;
    TreeNode<T>* root = new TreeNode<T> (pre[pStart]); //前序中的第一个元素构造临时根树
    //在中序中找到这个元素
    for (int i = inStart ; i <= inEnd ; i++) {
        if(vin[i] == pre[pStart]){
            //以找到的值左半边构造左树
            root->left = PreAndIn(pre, pStart + 1, pStart + i - inStart, vin, inStart, i-1);
            //以找到的值右半边构造右树
            root->right = PreAndIn(pre, pStart + i - inStart + 1, pEnd, vin, i + 1, inEnd);
        }
    }
    return root;
}
/*
 后序和中序遍历重建树
 */
template<class T>
static TreeNode<T> * BacAndIn(std::vector<T> bac, int bStart, int bEnd, std::vector<T> vin, int inStart, int inEnd){
    if(bStart > bEnd || inStart > inEnd)
        return nullptr;
    TreeNode<T> *root = new TreeNode<T>(bac[bEnd]);
    for (int i = inEnd; i >= inStart; i--) {
        if(vin[i] == bac[bEnd]){
            //以找到的值右半边构造右树
            root->right = BacAndIn(bac, bEnd - (inEnd - i) , bEnd - 1, vin, i+1, inEnd);
            //以找到的值左半边构造左树
            root->left = BacAndIn(bac, bStart , bEnd - (inEnd - i) - 1, vin, inStart, i-1);
        }
    }
    return root;
}

/*
 返回二叉树的高度
 */
template<class T>
int heightOfTree(TreeNode<T> *root){
    if(!root){
        return 0;
    }
    else{
        return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
    }
}

/*
 判断是否是一个BST
 */
int prev = INT_MIN;
bool flag = true;
bool isBST(TreeNode<int> *root){
    if(root->left && flag )
        isBST(root->left);
    if(root->val < prev)
        flag = false;
    prev = root->val;
    if(root->right && flag)
        isBST(root->right);
    return flag;
}
#endif /* TreeNode_h */
