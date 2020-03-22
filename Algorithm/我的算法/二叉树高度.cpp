//
//  二叉树高度.cpp
//  test
//
//  Created by yourui on 2020/3/11.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include "../C++Learning/TreeNode.h"
using namespace std;

template<typename T>
int heightOfTree(TreeNode<T> *root){
    if(!root){
        return 0;
    }
    else{
        return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
    }
}
int main(){
    return 0;
}
