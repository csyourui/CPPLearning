//
//  LinkedList.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/5.
//  Copyright © 2020 yourui. All rights reserved.
//

class node{
public:
    node *prev;
    node *next;
    node(){
        prev = nullptr;
        next = nullptr;
    }
};
class list{
private:
    node* head;
    node* tail;
public:
    list(){
        head = nullptr;
        tail = nullptr;
    }
    void push_back(node* n){
        if(!n) return;
        if(tail){
            tail -> next = n;
        }
        else{
            head = n;
        }
        n -> prev = tail;
        tail = n;
    }
    void remove(node* n){
        if(!n) return;
        node* curr = head;
        while(curr){
            if(curr == n){
                if(curr->prev && curr->next){
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    curr->next = nullptr;
                    curr->prev = nullptr;
                    delete curr;
                }
                else if(!curr->prev && curr->next){
                    head = curr->next;
                    head->prev = nullptr;
                    curr->next = nullptr;
                }
                else if(curr->prev && !curr->next){
                    tail = curr->prev;
                    tail->next = nullptr;
                    curr->prev = nullptr;
                }
                else{
                    head = nullptr;
                    tail = nullptr;
                }
            }
            curr = curr -> next;
        }
    }
};

int main(){
    list a;
    //a.push_back(<#node *n#>)
}
