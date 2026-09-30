class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // Head ko remove karna hai
        if(fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* temp_prev = NULL;
        while(fast != NULL) {
            temp_prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // slow is the node to remove
        temp_prev->next = slow->next;

        delete slow;

        return head;
    }
};