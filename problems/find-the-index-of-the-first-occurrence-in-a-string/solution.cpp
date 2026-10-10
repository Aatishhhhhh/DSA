
class Solution {
public:
    bool check_equal(int i, int j, const string& h, const string& n) {
        if (j == n.size()) {
            return true;
        }
        if (h[i] != n[j]) {
            return false;
        }
        return check_equal(i + 1, j + 1, h, n);
    }
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        int window_size = needle.size();
        for (int i = 0; i <= (int)haystack.size() - window_size; i++) {
            if (check_equal(i, 0, haystack, needle)) {
                return i;
            }
        }
        return -1;
    }
};
