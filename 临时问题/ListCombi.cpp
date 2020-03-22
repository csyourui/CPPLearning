//
//  ListCombi.cpp
//  test
//
//  Created by yourui on 2020/2/24.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include "ListNode.h"
using namespace std;

int main()
{
    int a, b;
    ListNode *Firsthead = new ListNode(NULL);
    ListNode *Secondhead = new ListNode(NULL);
    ListNode *Anshead = new ListNode(NULL);

    ListNode *pFirsthead = Firsthead;
    ListNode *pSecondhead = Secondhead;
    ListNode *pAnshead = Anshead;

    while(cin >> a){
        ListNode *newListNode = new ListNode(a);
        pFirsthead -> next = newListNode;
        pFirsthead = pFirsthead -> next;
        if(getchar() == '\n')
            break;
    }
    while(cin >> b){
        ListNode *newListNode = new ListNode(b);
        pSecondhead -> next = newListNode;
        pSecondhead = pSecondhead -> next;
        if(getchar() == '\n')
            break;
    }

    printList(Firsthead->next);
    printList(Secondhead->next);

    pFirsthead = Firsthead->next;
    pSecondhead = Secondhead->next;
    while (pFirsthead != NULL && pSecondhead != NULL) {
        if (pFirsthead -> val <= pSecondhead -> val) {
            ListNode *newListNode = pFirsthead;
            pAnshead -> next = newListNode;
            pAnshead = pAnshead -> next;
            pFirsthead = pFirsthead -> next;
        }
        else{
            ListNode *newListNode = pSecondhead;
            pAnshead -> next = newListNode;
            pAnshead = pAnshead -> next;
            pSecondhead = pSecondhead -> next;
        }
    }
    while (pFirsthead != NULL) {
        ListNode *newListNode = pFirsthead;
        pAnshead -> next = newListNode;
        pAnshead = pAnshead -> next;
        pFirsthead = pFirsthead -> next;
    }
    while (pSecondhead != NULL) {
        ListNode *newListNode = pSecondhead;
        pAnshead -> next = newListNode;
        pAnshead = pAnshead -> next;
        pSecondhead = pSecondhead -> next;
    }
    printList(Anshead->next);
}
