////
////  Huffman.cpp
////  C++Learning
////
////  Created by yourui on 2020/3/2.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//struct TreeNode{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v){
//        val = v;
//        left = NULL;
//        right = NULL;
//    }
//};
//vector<int> PrintFromTopToBottom(TreeNode* root) {
//    vector<int> res;
//    if(!root) return res;
//    queue<TreeNode*> q;
//    q.push(root);
//    while(!q.empty()){
//        res.push_back(q.front()->val);
//        if(q.front()->left)
//            q.push(q.front()->left);
//        if(q.front()->right)
//            q.push(q.front()->right);
//        q.pop();
//    }
//    return res;
//}
//
//TreeNode* CreateHuffman(int a[], int n){
//    TreeNode **b = new TreeNode*[n];
//    TreeNode *q = new TreeNode(0);
//    for(int i = 0; i < n; i++){
//        b[i] = new TreeNode(a[i]);
//    }
//    for (int i = 1; i < n; i++) {
//        int k1 = -1, k2 = 0;
//        for (int j = 0; j < n; j++) {
//            if(b[j] != NULL && k1 == -1){
//                k1 = j;
//                continue;
//            }
//            if(b[j]!=NULL){
//                k2 = j;
//                break;
//            }
//        }
//        for (int j = k2; j < n; j++) {
//            if(b[j]!=NULL){
//                if(b[j]->val < b[k1]->val){
//                    k2 = k1;
//                    k1 = j;
//                }
//                else if(b[j]->val < b[k2]->val){
//                    k2 = j;
//                }
//            }
//        }
//        q->val = b[k1]->val + b[k2]->val;
//        q->left = b[k1];
//        q->right = b[k2];
//        b[k1] = q;
//        b[k2] = NULL;
//    }
//    free(b);
//    return q;
//}
//
//int main(){
//    int a[] ={60, 45, 13, 69, 14, 5, 3};
//    vector<int> ans;
//    ans = PrintFromTopToBottom(CreateHuffman(a, 7));
//    for (auto x:ans) {
//        cout<<x<<" ";
//    }
//    cout<<endl;
//    return 0;
//}
