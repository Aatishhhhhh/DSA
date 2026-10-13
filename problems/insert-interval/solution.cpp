class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int current_interval = 0;
        vector<vector<int>> ans;
        int found = 0;
        vector<int> insertion = newInterval;
        while(current_interval < intervals.size()) {
            if(intervals[current_interval][1] < insertion[0]) {
                ans.push_back(intervals[current_interval]);
            }
            else if(intervals[current_interval][0] > insertion[1]) {
                if(found == 0) {
                    ans.push_back(insertion);
                    found = 1;
                }
                ans.push_back(intervals[current_interval]);
            }
            else {
                insertion[0] = min(insertion[0],
                                   intervals[current_interval][0]);
                insertion[1] = max(insertion[1],
                                   intervals[current_interval][1]);
            }
            current_interval++;
        }
        if(found == 0) {
            ans.push_back(insertion);
        }
        return ans;
    }
};