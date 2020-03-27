//
//  7_重建二叉树.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

//前序和中序
TreeNode* handler(vector<int> pre, int preStart, int preEnd, vector<int> in, int inStart, int inEnd){
    if((preStart > preEnd) ||(inStart > inEnd))
        return NULL;
    TreeNode* root = new TreeNode(pre[preStart]);
    for(int i = inStart; i <= inEnd; i++){
        if(in[i]==pre[preStart]){
            root->left = handler(pre, preStart+1, preStart+i-inStart, in, inStart, i - 1);
            root->right = handler(pre, preStart+i-inStart+1, preEnd, in, i + 1, inEnd);
        }
    }
    return root;
}
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    TreeNode* root;
    root = handler(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    return root;
}
