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
        ListNode *temp=dummy;
        priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>,greater<pair<int, ListNode*>>>heap;

        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                heap.push({lists[i]->val,lists[i]});
            }
        }
        while(!heap.empty()){
            ListNode *movetemp=nullptr;
            temp->next=heap.top().second;
            temp=temp->next;
            movetemp=heap.top().second;
            if(movetemp->next!=nullptr){
                heap.pop();
                heap.push({movetemp->next->val,movetemp->next});
            }
            else
            heap.pop();
        }
        temp->next=nullptr;
        return dummy->next;
    }
};
