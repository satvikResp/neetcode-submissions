class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr || left == right)
            return head;

        ListNode* prevLeft = nullptr;
        ListNode* leftNode = head;

        // left node aur uske previous tak jao
        for (int i = 1; i < left; i++) {
            prevLeft = leftNode;
            leftNode = leftNode->next;
        }

        // Reverse
        ListNode* prev = nullptr;
        ListNode* curr = leftNode;

        for (int i = left; i <= right; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Connect last part
        leftNode->next = curr;

        // Connect first part
        if (prevLeft != nullptr)
            prevLeft->next = prev;
        else
            head = prev;

        return head;
    }
};