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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        vector<int> final_list;

        while(temp1 != NULL && temp2 != NULL){

            if(temp1->val <= temp2->val){
                final_list.push_back(temp1->val);
                temp1 = temp1->next;
            }
            else{
                final_list.push_back(temp2->val);
                temp2 = temp2->next;
            }
        }

        while(temp1 != NULL){
            final_list.push_back(temp1->val);
            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            final_list.push_back(temp2->val);
            temp2 = temp2->next;
        }

        ListNode* start = NULL;
        ListNode* end = NULL;

        for(int i = 0; i < final_list.size(); i++){

            ListNode* newNode = new ListNode(final_list[i]);

            if(start == NULL){
                start = newNode;
                end = newNode;
            }
            else{
                end->next = newNode;
                end = newNode;
            }
        }
        return start;
    }
};