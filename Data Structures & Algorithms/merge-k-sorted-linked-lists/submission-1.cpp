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
        vector<int>nodes;

        for(int i=0;i<lists.size();i++){
            ListNode *temp=lists[i];
            while(temp!=nullptr){
                nodes.push_back(temp->val);
                temp=temp->next;
            }
        }
        ListNode *dummy=new ListNode(0);
        ListNode *temp=dummy;
        sort(nodes.begin(),nodes.end());
        for(int i=0;i<nodes.size();i++){
            ListNode *newnode=new ListNode(nodes[i]);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }


};
