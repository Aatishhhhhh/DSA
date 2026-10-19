class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        while(index < nums.size() - 1) {
            if(nums[index] == 0) {
                return false;
            }
            else {
                int val = nums[index];
                int i;
                int max_index = index + 1;
                for(i = index + 1; i <= index + val && i < nums.size(); i++) {
                    if(max_index + nums[max_index] < i + nums[i]) {
                        max_index = i;
                    }
                }
                index = max_index;
            }
        }
        return true;
    }
};