class Solution {
public:
    int lengthOfLastWord(string s) {

        if(s.empty()) {
            return 0;
        }
        int end_index = s.size() - 1;
        while(end_index >= 0 && s[end_index] == ' ') {
            end_index--;
        }
        int length = 0;
        while(end_index >= 0 && s[end_index] != ' ') {
            length++;
            end_index--;
        }
        return length;
    }
};