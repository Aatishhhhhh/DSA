class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() < numRows || numRows == 1){
            return s;
        }
        vector<string> rows(numRows);
        int i, factor = -1, row =0;
        for(i=0; i< s.size(); i++){
            if(row == 0 || row == numRows-1){
                factor = factor * -1;
            }
            rows[row] += s[i];
            row = row+ factor;
        }
        string ans = "";

        for(string r : rows)
            ans += r;
        return ans;
    }
};