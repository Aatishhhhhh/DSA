class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        for(int i = 0; i < gas.size(); i++) {
            diff.push_back(gas[i] - cost[i]);
        }
        int total = 0;
        int tank = 0;
        int start = 0;
        for(int i = 0; i < diff.size(); i++) {
            total += diff[i];
            tank += diff[i];
            if(tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        if(total < 0) {
            return -1;
        }
        return start;
    }
};