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

        for(ListNode* list :lists){
            while(list){
            nodes.push_back(list->val);
            list=list->next;
            }
        }
        sort(nodes.begin(),nodes.end());
        ListNode *nayilist=new ListNode(0);
        ListNode *temp=nayilist;

        for(int i=0;i<nodes.size();i++){
            temp->next=new ListNode(nodes[i]);
            temp=temp->next;
        }
        return nayilist->next;
    }

};
