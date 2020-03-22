//
//  反转链表.cpp
//  test
//
//  Created by yourui on 2020/3/10.
//  Copyright © 2020 yourui. All rights reserved.
//

#include "../C++Learning/ListNode.h"

ListNode* reverseList(ListNode *l1){
    ListNode* curr = l1;
    ListNode* prev = nullptr;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main(){
    srand((unsigned)time(NULL));
    ListNode* l1 = randomOrderedList(12);
    printList(l1);
    printList(reverseList(l1));
    
}
