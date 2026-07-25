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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;
        
         
        while(true){
        int  mini=INT_MAX;
        ListNode *mininode=nullptr;
        int index=-1;
        for(int i=0;i<lists.size();i++){
            if (lists[i] == nullptr) continue;

           
            ListNode *temp=lists[i];
            if(temp->val<mini){
                index=i;
                mini=temp->val;
                mininode=temp;
            }
        }
        if (mini == INT_MAX)
        break;

        lists[index]=lists[index]->next;
        curr->next=mininode;
        curr=curr->next;
        }
        curr->next=nullptr;
        return dummy->next;

    }
};
