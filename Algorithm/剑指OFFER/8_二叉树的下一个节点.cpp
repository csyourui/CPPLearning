//
//  8_二叉树的下一个节点.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    //如果右节点不为空，则下一个为右子树的最左子节点
    if(pNode->right){
        TreeLinkNode* t = pNode->right;
        while(t->left)
            t = t->left;
        return t;
    }else{
     //否则一直往上找父代，直到找到是从父代左子爬上去的父代，输出那个父代
        while(pNode->next){
            TreeLinkNode* t = pNode->next;
            if(t->left == pNode)
                return t;
            pNode = pNode->next;
        }
    }
    return NULL;
}
