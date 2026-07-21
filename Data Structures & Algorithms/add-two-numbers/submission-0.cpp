class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* temp = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {

            int val1 = 0;
            int val2 = 0;

            if (l1) {
                val1 = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            int sum = val1 + val2 + carry;

            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy.next;
    }
};