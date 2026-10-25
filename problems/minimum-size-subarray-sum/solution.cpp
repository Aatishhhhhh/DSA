class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size(), sum = 0, left = 0;
        int right = 0, found = 0;
        if(target == 1 || nums[0] >= target){
            return 1;
        }
        else{
            int arrSum = 0;
            while(left <= right && right < nums.size()){
                arrSum += nums[right];
                while( arrSum >= target ){
                    found = 1;
                    if(len > (right - left + 1)){
                        len = (right - left + 1);
                    }
                    arrSum -= nums[left];
                    left++;
                }
                right++;
            }
        }
        if(found == 0 ){
            return 0;
        }
        else{
            return len;
        }
    }
};