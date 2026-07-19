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
        ListNode *temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        vector<ListNode*>arr;
        temp=head;
        while(temp!=nullptr){
            arr.push_back(temp);
            temp=temp->next;
        }
        
        
        int l=0,r=cnt-1;

        ListNode dummy(0);
        dummy.next=head;
        temp=&dummy;
        while(l<r){
            temp->next=arr[l];
            l++;
            temp=temp->next;
            temp->next=arr[r];
            r--;
            temp=temp->next;
        }
        if(l == r){
            temp->next = arr[l];
            temp = temp->next;
        }

        // Very important
        temp->next = nullptr;
    }
};
