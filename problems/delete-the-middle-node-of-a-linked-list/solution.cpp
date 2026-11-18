class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* middle = NULL;
        while(fast != NULL && fast->next != NULL) {
            middle = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        middle->next = slow->next;
        return head;
    }
};