class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Har positive number ko uski correct index par rakho
        for(int i = 0; i < n; i++) {
            while(nums[i] >= 1 &&
                  nums[i] <= n &&
                  nums[nums[i] - 1] != nums[i]) {

                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // Ab check karo kaunsa number apni jagah par nahi hai
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};