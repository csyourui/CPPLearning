//
//  字典树.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode{
private:
    TrieNode *children[26];
public:
    int count;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
            count = 0;
        }
    }
    TrieNode* get(char c){
        if(children[c-'a']==nullptr){
            children[c-'a'] = new TrieNode();
            count++;
        }
        return children[c-'a'];
    }
};
int minimumLengthEncoding(vector<string>& words){
    TrieNode* trie = new TrieNode();
    unordered_map<TrieNode*, int> nodes;
    for (int i = 0; i < (int)words.size(); i++) {
        string str = words[i];
        TrieNode* cur =trie;
        for(int k = (int)str.length()-1; k >=0; k--){
            cur = cur->get(str[k]);
        }
        nodes[cur] = i;
    }
    int res = 0;
    unordered_map<TrieNode*, int>::iterator it;
    for (it = nodes.begin(); it != nodes.end(); it++) {
        if(it->first->count == 0){
            res += words[it->second].length()+1;
        }
    }
    return res;
}
