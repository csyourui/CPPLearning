//
//  重建二叉树.cpp
//  test
//
//  Created by yourui on 2020/3/11.
//  Copyright © 2020 yourui. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include "../C++Learning/TreeNode.h"
using namespace std;


//前序和中序遍历重建树
template<typename T>
TreeNode<T>* PreAndIn(vector<T> pre, int pStart, int pEnd, vector<T> vin, int inStart, int inEnd){
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
//后序和中序遍历重建树
template<typename T>
TreeNode<T> * BacAndIn(vector<T> bac, int bStart, int bEnd, vector<T> vin, int inStart, int inEnd){
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
int main(){
    /*
             A
           /   \
          B     C
         / \   /
        D   E F
     
     
     */
    vector<char> pre = {'A','B','D','E','C','F'};//前序遍历
    vector<char> vin = {'D','B','E','A','F','C'};//中序遍历
    vector<char> bac = {'D','E','B','F','C','A'};//后序遍历
    TreeNode<char> *root1 = PreAndIn(pre, 0, (int)pre.size()-1, vin, 0, (int)vin.size()-1);
    TreeNode<char> *root2 = BacAndIn(bac, 0, (int)bac.size()-1, vin, 0, (int)vin.size()-1);

    int a = 0;
}

