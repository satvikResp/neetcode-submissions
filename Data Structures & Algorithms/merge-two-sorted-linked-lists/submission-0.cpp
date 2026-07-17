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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newlist=nullptr;
        ListNode *newhead=newlist;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val < list2->val){
                if(newlist==nullptr){
                    newlist=list1;
                    newhead=newlist;
                }
                else{
                    newlist->next=list1;
                    newlist=newlist->next;
                }
                list1=list1->next;
                
            }
            else{
                if(newlist==nullptr){
                   newlist=list2;
                   newhead=newlist;
                }
                else{
                    newlist->next=list2;
                    newlist=newlist->next;
                }
                list2=list2->next;
                  
                
            }
        }
        while(list1!=nullptr){
             if(newlist==nullptr){
                    newlist=list1;
                    newhead=newlist;
                }
                else{
                    newlist->next=list1;
                } 
                break;
        }
        while(list2!=nullptr){
              if(newlist==nullptr){
                   newlist=list2;
                   newhead=newlist;
                }
                else{
                    newlist->next=list2;
                     
                }    
                break; 
        }
        return newhead;
    }
};
