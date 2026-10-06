class Solution {
public:
    vector<int> find_min(vector<ListNode*>& pointers) {
        int min = INT_MAX;
        int min_index = -1;
        for(int i = 0; i < pointers.size(); i++) {
            if(pointers[i] == NULL) {
                continue;
            }
            if(pointers[i]->val < min) {
                min = pointers[i]->val;
                min_index = i;
            }
        }
        // Sab lists khatam
        if(min_index == -1) {
            return {-1, -1};
        }
        // [index, minimum value]
        return {min_index, min};
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> pointers(lists.size());
        // Har list ka starting node store karo
        for(int i = 0; i < lists.size(); i++) {
            pointers[i] = lists[i];
        }
        vector<int> final_list;
        while(true) {
            vector<int> res = find_min(pointers);
            // Sab pointers NULL → saari lists khatam
            if(res[0] == -1) {
                break;
            }
            // Minimum value result mein daalo
            final_list.push_back(res[1]);
            // Us list ko next node par move karo
            pointers[res[0]] = pointers[res[0]]->next;
        }
        // final_list ko linked list mein convert karo
        ListNode* start = NULL;
        ListNode* tail = NULL;
        for(int i = 0; i < final_list.size(); i++) {
            ListNode* node = new ListNode(final_list[i]);
            if(start == NULL) {
                start = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        return start;
    }
};