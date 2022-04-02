class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int currMin = prices[0];
        for(int i=1;i<n;i++){
            currMin = min(currMin, prices[i]);
            profit = max(profit, prices[i] - currMin);
        }
        return profit;
    }
};