class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        // Step 1: Insertion sort
        for(int i = 1; i < n; i++) {
            int j = i;

            while(j > 0 && nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }

        // Step 2: Initialize with a valid sum of 3 elements
        int final_sum = nums[0] + nums[1] + nums[2];
        int diff = abs(target - final_sum);

        // Step 3: Fix one element and use two pointers
        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int currentsum = nums[i] + nums[left] + nums[right];
                int currentdiff = abs(target - currentsum);

                // Update best answer if this sum is closer
                if(currentdiff < diff) {
                    diff = currentdiff;
                    final_sum = currentsum;
                }

                // Exact match: no answer can be closer
                if(currentsum == target) {
                    return target;
                }
                else if(currentsum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return final_sum;
    }
};
