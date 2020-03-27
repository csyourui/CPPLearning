//
//  6_从尾到头打印链表.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
//逆序链表（头插法）， 用栈存储，
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> ans;
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while(curr){
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    while(prev){
        ans.push_back(prev->val);
        prev = prev->next;
    }
    return ans;
}
