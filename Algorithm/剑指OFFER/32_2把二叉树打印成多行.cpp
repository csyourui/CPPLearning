//
//  32_2把二叉树打印成多行.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//
//用Q.size()判断一行多少个
vector<vector<int>> Print(TreeNode* pRoot) {
    vector<vector<int>> res;
    if(!pRoot) return res;
    queue<TreeNode*> Q;
    Q.push(pRoot);
    while(!Q.empty()){
        int len = Q.size();
        vector<int> tempRes;
        for(int i = 0; i < len; i++){
            TreeNode* t = Q.front();
            Q.pop();
            tempRes.push_back(t->val);
            if(t->left) Q.push(t->left);
            if(t->right) Q.push(t->right);
        }
        res.push_back(tempRes);
    }
    return res;
}
