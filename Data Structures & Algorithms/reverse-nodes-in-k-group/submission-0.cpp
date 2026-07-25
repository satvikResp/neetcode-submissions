class Solution {
    void reverse(ListNode *head,int k){
        //pehla return krna hia 
        ListNode *purana=head;
        ListNode *curr=head->next;
        
        ListNode *prev=nullptr;
        ListNode *nxt=nullptr;
        for(int i=1;i<=k && curr!=nullptr;i++){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        //prev ko point krenge pichle to  return krna hai 
        //jodna bhi hai abhi to prev ke last me jo hai uska next
        ListNode *topoint=prev;
        while(topoint->next!=nullptr){
            topoint=topoint->next;
        }
        topoint->next=nxt;
        purana->next=prev;

    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *mover=dummy;

        ListNode*temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int tomove=count/k;
        if(tomove==0) return head;

       int it=0;
      

       while(it<tomove){
        reverse(mover,k);
        it++;

        for(int i=0;i<k;i++){
            mover=mover->next;
        }
       }
        return dummy->next;
    }
};
