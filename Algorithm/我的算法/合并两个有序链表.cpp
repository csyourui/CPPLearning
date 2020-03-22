//
//  合并两个有序链表.cpp
//  test
//
//  Created by yourui on 2020/3/10.
//  Copyright © 2020 yourui. All rights reserved.
//

#include "../lib/ListNode.h"
ListNode* mergeListNodes(ListNode* l1, ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val <= l2->val){
        l1->next = mergeListNodes(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeListNodes(l1, l2->next);
        return l2;
    }
}
int main(){
    srand((unsigned)time(NULL));
    ListNode* l1 = randomList(5);
    ListNode* l2 = randomList(6);
    printList(l1);
    printList(l2);
    
    printList(mergeListNodes(l1, l2));
}
