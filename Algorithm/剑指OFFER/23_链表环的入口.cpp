//
//  24_链表环的入口.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
//从快指针慢指针的相遇点，开始和头指针一起走，相遇点为入口
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(!pHead || !pHead->next || !pHead->next->next) return nullptr;
    ListNode* Fast = pHead->next->next;
    ListNode* Slow = pHead->next;
    ListNode* res = pHead;
    while(Fast != Slow){
        Fast = Fast->next->next;
        Slow = Slow->next;
    }
    while(res != Slow){
        res = res->next;
        Slow = Slow->next;
    }
    return res;
}
