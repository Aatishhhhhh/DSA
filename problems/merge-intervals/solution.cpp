class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        int old_index = 0;
        int new_index = 1;
        vector<vector<int>> ans;
        vector<int> overlaps = intervals[old_index];
        while (new_index < intervals.size()) {
            if (intervals[new_index][0] <= overlaps[1]) {
                vector<int> merged = {
                    min(overlaps[0], intervals[new_index][0]),
                    max(overlaps[1], intervals[new_index][1])
                };
                overlaps = merged;
            }
            else {
                ans.push_back(overlaps);
                old_index = new_index;
                overlaps = intervals[old_index];
            }
            new_index++;
        }
        ans.push_back(overlaps);
        return ans;
    }
};
