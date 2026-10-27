class Solution {
public:
    void row(vector<int>& ans, vector<vector<int>>& matrix,
             int& top, int& bottom, int& left, int& right, int op) {
        if(top > bottom || left > right)
            return;
        int k;
        if(op > 0) {
            for(k = left; k <= right; k++) {
                ans.push_back(matrix[top][k]);
            }
            top++;
        }
        else {
            for(k = right; k >= left; k--) {
                ans.push_back(matrix[bottom][k]);
            }
            bottom--;
        }
        col(ans, matrix, top, bottom, left, right, op);
    }
    void col(vector<int>& ans, vector<vector<int>>& matrix,
             int& top, int& bottom, int& left, int& right, int op) {
        if(top > bottom || left > right)
            return;

        int k;
        if(op > 0) {
            for(k = top; k <= bottom; k++) {
                ans.push_back(matrix[k][right]);
            }
            right--;
        }
        else {
            for(k = bottom; k >= top; k--) {
                ans.push_back(matrix[k][left]);
            }
            left++;
        }
        row(ans, matrix, top, bottom, left, right, -op);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty() || matrix[0].empty())
            return ans;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        row(ans, matrix, top, bottom, left, right, 1);
        return ans;
    }
};