//
//  34_二叉树中和为某一值的路径.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

void dfs(vector<vector<int>> &res, vector<int> temp, TreeNode* root,int expectNumber){
    if(!root) return;
    temp.push_back(root->val);
    expectNumber -= root->val;
    if(expectNumber == 0 && !root->left && !root->right) {
        res.push_back(temp);
    }else{
        dfs(res, temp, root->left, expectNumber);
        dfs(res, temp, root->right, expectNumber);
    }
    expectNumber += root->val;
    temp.pop_back();
}
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int>> res;
    vector<int> temp;
    //root为空或者，root的值大于expertNumber, 返回空res
    if(!root || root->val > expectNumber) return res;
    dfs(res,temp, root, expectNumber);
    return res;
}
