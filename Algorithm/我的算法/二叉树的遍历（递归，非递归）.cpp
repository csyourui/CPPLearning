//
//  二叉树的遍历（递归，非递归）.cpp
//  test
//
//  Created by yourui on 2020/3/15.
//  Copyright © 2020 yourui. All rights reserved.
//

#include "../C++Learning/TreeNode.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//先序遍历——先访问根节点，再访问左子树，最后访问右子树
template<typename T>
void preorder(TreeNode<T> *root){
    if(root == NULL) return;
    cout << root->val;
    preorder(root->left);
    preorder(root->right);
}
//中序遍历——先访问左子树，再访问根节点，最后访问右子树
template<typename T>
void inorder(TreeNode<T> *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}
//后序遍历——先访问左子树，再访问右子树，最后访问根节点
template<typename T>
void postorder(TreeNode<T> *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val;
}
//层序遍历 用队列实现
template<typename T>
void levelorder(TreeNode<T> *root){
    queue<TreeNode<T>*> myQueue;
    TreeNode<T> *temp;
    myQueue.push(root);
    while(!myQueue.empty()){
        temp = myQueue.front();
        myQueue.pop();
        cout<<temp->val;
        if(temp->left)
            myQueue.push(temp->left);
        if(temp->right)
            myQueue.push(temp->right);
    }
}

//先序遍历 非递归 用栈实现
template<typename T>
void preorder2(TreeNode<T> *root){
    stack<TreeNode<T>*> preStack;
    TreeNode<T> *temp;
    preStack.push(root);
    while(!preStack.empty()){
        temp = preStack.top();
        preStack.pop();
        cout<<temp->val;
        if(temp->right)
            preStack.push(temp->right);
        if(temp->left)
            preStack.push(temp->left);
    }
}

//中序遍历 非递归 将左子一直往栈中放
template<typename T>
void inorder2(TreeNode<T> *root){
    stack<TreeNode<T>*> inStack;
    TreeNode<T> *temp = root;
    while(!inStack.empty()||temp){
        if(temp){
            inStack.push(temp);
            temp = temp->left;
        }
        else{
            temp = inStack.top();
            inStack.pop();
            cout<<temp->val;
            temp = temp->right;
        }
    }
}
//后序遍历 非递归 左子一直压栈，设置记录点，若右子有且不为记录点则右子压栈，否则弹出栈顶
template<typename T>
void postorder2(TreeNode<T> *root){
    stack<TreeNode<T>*> bacStack;
    TreeNode<T>* record = nullptr;
    TreeNode<T>* p = root;
    while (!bacStack.empty() || p) {
        if(p){
            bacStack.push(p);
            p = p->left;
        }
        else{
            p = bacStack.top();
            if(p->right && p->right != record){
                p = p->right;
            }
            else{
                bacStack.pop();
                cout<<p->val;
                record = p;
                p = nullptr;
            }
        }
    }
}


int main(){
    /*
             A
           /   \
          B     C
         / \   /
        D   E F
     
     
     */
//    vector<char> pre = {'A','B','D','E','C','F'};//前序遍历
//    vector<char> vin = {'D','B','E','A','F','C'};//中序遍历
//    vector<char> bac = {'D','E','B','F','C','A'};//后序遍历
    

    vector<int> pre = {5, 3, 2, 4, 7, 6, 8};//前序遍历
    vector<int> vin = {2, 3, 4, 5, 6, 7, 8};//中序遍历
    vector<int> bac = {2, 4, 3, 6, 8, 7, 5};//后序遍历
    
    TreeNode<int> *root1 = PreAndIn(pre, 0, (int)pre.size()-1, vin, 0, (int)vin.size()-1);
    postorder2(root1);
    cout<<endl;
    
    //int a = 0;
}
