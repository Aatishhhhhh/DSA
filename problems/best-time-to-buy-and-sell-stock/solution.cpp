class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int difference = 0, min_index = 0;
        for(i=0; i< prices.size(); i++){
            int current_difference;
            if(prices[i] < prices[min_index]){
                min_index = i;
            }
            else if(prices[i] > prices[min_index]){
                current_difference = prices[i] - prices[min_index];
                if(current_difference > difference){
                    difference = current_difference;
                }
            }
        }
        return difference;
    }
};