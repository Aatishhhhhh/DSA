class Solution {
public:
    void backtrackCombination(
        int current,
        int n,
        int k,
        vector<vector<int>>& ans,
        vector<int>& permutation
    ) {
        if(permutation.size() == k) {
            ans.push_back(permutation);
            return;
        }
        for(int next = current; next <= n; next++) {
            permutation.push_back(next);
            backtrackCombination(
                next + 1, n, k, ans, permutation
            );
            permutation.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> permutation;
        backtrackCombination(1, n, k, ans, permutation);
        return ans;
    }
};