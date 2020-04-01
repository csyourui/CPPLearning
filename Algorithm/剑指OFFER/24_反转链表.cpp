//
//  24_反转链表.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

ListNode* ReverseList(ListNode* pHead) {
    ListNode* curr = pHead;
    ListNode* prev = nullptr;
    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
