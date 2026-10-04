class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL) {

            if(temp->val == temp->next->val) {

                ListNode* nextnode = temp->next;

                temp->next = nextnode->next;

                delete nextnode;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};