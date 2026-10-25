class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0);
        int left = 0, right = 0;
        int len = 0;
        while(right < s.size()) {
            char ch = s[right];
            if(freq[ch] > 0) {
                freq[s[left]]--;
                left++;
            }
            else {
                freq[ch]++;
                if(len < right - left + 1) {
                    len = right - left + 1;
                }
                right++;
            }
        }
        return len;
    }
};