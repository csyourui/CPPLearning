//
//  32_3按之字形顺序打印二叉树.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//
//增加一个计数器判断是奇数行还是偶数行，调用reverse(v.begin(), v.end())逆转vector
vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> res;
    if(!pRoot) return res;
    queue<TreeNode*> Q;
    Q.push(pRoot);
    int count = 0;
    while(!Q.empty()){
        count++;
        int len = Q.size();
        vector<int> tempRes;
        for(int i = 0; i < len; i++){
            TreeNode* t = Q.front();
            Q.pop();
            tempRes.push_back(t->val);
            if(t->left) Q.push(t->left);
            if(t->right) Q.push(t->right);
        }
        if(count%2==0)
            reverse(tempRes.begin(), tempRes.end());
        res.push_back(tempRes);
    }
    return res;
}
