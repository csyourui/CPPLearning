//
//  ListNode.h
//  test
//
//  Created by yourui on 2020/2/24.
//  Copyright © 2020 yourui. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void printList();
};
void ListNode::printList()
{
    ListNode* phead= this;

    while(phead->next!=NULL){
        printf("%d ",phead->val);
        phead = phead -> next;
    }
    printf("%d \n",phead->val);
}
ListNode* randomOrderedList(int n){
    ListNode* res = new ListNode(-1);
    ListNode* cur = res;
    int start =rand() % 5 + 1;
    while (n--) {
        ListNode* temp = new ListNode(start);
        cur->next = temp;
        cur = cur->next;
        start += rand()% 2 + 1;
    }
    return res->next;
}
ListNode* randomList(int n){
    ListNode* res = new ListNode(-1);
    ListNode* cur = res;
    while (n--) {
        ListNode* temp = new ListNode(rand() % 20 + 1);
        cur->next = temp;
        cur = cur->next;
    }
    return res->next;
}
/*
 组合两个有序链表
 */
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
/*
 反转链表
 */
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


#endif /* ListNode_h */
