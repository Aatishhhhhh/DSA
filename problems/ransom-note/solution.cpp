class Solution {
public:
    vector<int> hashing(string s) {
        vector<int> hashmap(26, 0);
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            hashmap[ch - 'a']++;
        }
        return hashmap;
    }
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) {
            return false;
        }
        vector<int> ransomHash = hashing(ransomNote);
        vector<int> magazineHash = hashing(magazine);
        for(int j = 0; j < 26; j++) {
            if(ransomHash[j] > magazineHash[j]) {
                return false;
            }
        }
        return true;
    }
};