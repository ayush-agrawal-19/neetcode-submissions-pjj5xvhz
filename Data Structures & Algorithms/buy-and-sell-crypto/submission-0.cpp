class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        for (int i=0; i<prices.size(); i++) {
            int j = 0;

            while (j < i) {
                int profit = prices[i] - prices[j];
                if (profit > max_profit) {
                    max_profit = profit;
                }
                j++;
            }
        }

        return max_profit;
    }
};
