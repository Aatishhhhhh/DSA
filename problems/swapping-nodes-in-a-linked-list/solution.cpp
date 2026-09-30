class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 1; i < k; i++) {
            fast = fast->next;
        }

        ListNode* first_node = fast;

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* second_node = slow;

        int temp = first_node->val;
        first_node->val = second_node->val;
        second_node->val = temp;

        return head;
    }
};