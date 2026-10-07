class Solution {
public:
    void recurse_combination(
        vector<int>& candidates,
        int next_target,
        int index,
        vector<vector<int>>& ans,
        vector<int>& combination
    ) {
        // Target complete
        if(next_target == 0) {
            ans.push_back(combination);
            return;
        }
        // Candidates khatam
        if(index == candidates.size()) {
            return;
        }
        // Candidate choose karo
        if(candidates[index] <= next_target) {
            combination.push_back(candidates[index]);
            // Same index because candidate can be reused
            recurse_combination(
                candidates,
                next_target - candidates[index],
                index,
                ans,
                combination
            );
            // Undo
            combination.pop_back();
        }
        // Candidate skip karo, next candidate try karo
        recurse_combination(
            candidates,
            next_target,
            index + 1,
            ans,
            combination
        );
    }
    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {
        vector<vector<int>> ans;
        vector<int> combination;
        recurse_combination(
            candidates,
            target,
            0,
            ans,
            combination
        );
        return ans;
    }
};