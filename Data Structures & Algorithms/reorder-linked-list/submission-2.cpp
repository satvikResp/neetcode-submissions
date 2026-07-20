/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

     
    ListNode* nxt=nullptr;
    ListNode *curr=slow->next;
    slow->next=nullptr;
    ListNode * temphead=nullptr;
    while(curr!=nullptr){
        nxt=curr->next;
        curr->next=temphead;
        temphead=curr;
        curr=nxt;
    }
    slow=head;
    
      
ListNode* first=head;
ListNode* second=temphead;
    while(first && second){
       ListNode* tmp1 = first->next;     // Save first list ka next
ListNode* tmp2 = second->next;    // Save second list ka next

first->next = second;   // 1 -> 5
second->next = tmp1;    // 5 -> 2

first = tmp1;           // first ko aage badhao
second = tmp2;          // second ko aage badhao
    }
   


    }
};
