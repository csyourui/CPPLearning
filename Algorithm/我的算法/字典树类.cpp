//
//  字典树类.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/1.
//  Copyright © 2020 yourui. All rights reserved.
//


#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode{
public:
    int path;
    int end;
    TrieNode *next[26];
    
    TrieNode(){
        path = 0;
        end = 0;
        for(int i = 0; i < 26; i++){
            next[i] = nullptr;
        }
    }
};

class TrieTree{
public:
    TrieNode *root;
    TrieTree(){
        root = new TrieNode();
    }
    void Insert(const string &str){
        TrieNode* phead = root;
        phead->path++;

        for(int i = 0; i < str.length(); i++){
            int num = str[i]- 'a';
            if(!phead->next[num]){
                phead->next[num] = new TrieNode;
            }
            phead = phead->next[num];
            phead->path++;

        }
        phead->end++;
    }
    bool Search(const string &str){
        if(str == "") return false;
        TrieNode* phead = root;
        for(int i = 0; i < str.length(); i++){
            int num = str[i]-'a';
            if(!phead->next[num]){
                return false;
            }else{
                phead = phead->next[num];
            }
        }
        return phead->end > 0;
    }
    bool Delete(const string &str){
        if(Search(str)){
            TrieNode* phead = root;
            phead->path--;
            for (int i = 0; i < (int)str.length(); i++) {
                int num = str[i]-'a';
                if(--phead->next[num]->path == 0){
                    phead->next[num] = nullptr;
                    return true;
                }
                phead = phead->next[num];
            }
            phead->end--;
            return true;
        }
        else{
            return false;
        }
    }
    int prefixNumber(const string &str){
        if(str == "") return 0;
        TrieNode* phead = root;
        for (int i = 0; i < (int)str.length(); i++) {
            int num = str[i] - 'a';
            if(!phead->next[num]){
                return 0;
            }
            phead = phead->next[num];
        }
        return phead->path;
    }
};


int main(int argc, const char * argv[])
{
    TrieTree A;
    A.Insert("apple");
    A.Insert("appoo");
    A.Insert("apooo");

    if(A.Search("appl")){
        printf("查询到了\n");
    }else{
        printf("没查询到\n");
    }
    return 0;
}

