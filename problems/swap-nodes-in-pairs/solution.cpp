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
    ListNode* swapPairs(ListNode* head) {

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL && temp->next != NULL) {

            ListNode* second = temp->next;
            ListNode* tempNode = second->next;

            if(temp == head) {
                head = second;

                second->next = temp;
                temp->next = tempNode;
            }
            else {
                prev->next = second;
                second->next = temp;
                temp->next = tempNode;
            }

            prev = temp;
            temp = tempNode;
        }

        return head;
    }
};