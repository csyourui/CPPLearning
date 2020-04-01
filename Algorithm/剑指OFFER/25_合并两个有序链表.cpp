//
//  25_合并两个有序链表.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/28.
//  Copyright © 2020 yourui. All rights reserved.
//

ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(!pHead1)
        return pHead2;
    if(!pHead2)
        return pHead1;
    if(pHead1->val <= pHead2->val){
        pHead1->next = Merge(pHead1->next, pHead2);
        return pHead1;
    }
    else{
        pHead2->next = Merge(pHead1, pHead2->next);
        return pHead2;
    }
}
