//
//  22_链表中倒数第K个点.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//
//两个指针，一个先走k步，再一起走，快指针到头时，慢指针为倒数第k个
#include <stdio.h>
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    //1 2 3 4 5 n = 2
    if(pListHead == nullptr || k < 1){
        return nullptr;
    }
    //
    //4 5
    ListNode* p1 = pListHead;
    ListNode* p2 = pListHead;

    for(int i = 0; i < k; i++){
        if(!p1)
            return nullptr;
        p1 = p1->next;
    }
    while(p1){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}
