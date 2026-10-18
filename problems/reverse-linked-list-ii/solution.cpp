class Solution {
public:
    ListNode* reverse_list(ListNode* temp, int num) {
        ListNode* cnode = temp;
        ListNode* pnode = NULL;
        for(int i = 0; i < num; i++) {
            ListNode* nnode = cnode->next;
            cnode->next = pnode;
            pnode = cnode;
            cnode = nnode;
        }
        return pnode;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) {
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* ahead = NULL;
        int count = 1;
        while(count < left) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        int num = right - left + 1;
        ahead = temp;
        for(int i = 0; i < num; i++) {
            ahead = ahead->next;
        }
        ListNode* cnode = reverse_list(temp, num);
        if(prev != NULL) {
            prev->next = cnode;
        }
        else {
            head = cnode;
        }
        temp->next = ahead;
        return head;
    }
};