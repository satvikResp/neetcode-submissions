 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==nullptr){
            return nullptr;
     }
    
    int count = 0;
    ListNode* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
 
     
    n=count-n;
    if(head->next==nullptr || n==0){
            head=head->next;
            return head;
    }
        
    temp=head;
    for(int i=0;i<n-1 && temp->next!=nullptr;i++){
        temp=temp->next;
    }

    temp->next=temp->next->next;

    return head;
    }
};
