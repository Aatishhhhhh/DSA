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
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        vector<int> sHash = hashing(s);
        vector<int> tHash = hashing(t);
        for(int j = 0; j < 26; j++) {
            if(tHash[j] != sHash[j]) {
                return false;
            }
        }
        return true;
    }
};