class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int minprice = prices[0];
       int profit;
       int maxprofit =0;

       for(int i = 1; i < n; i++){
        minprice = min(minprice, prices[i]);
        profit = prices[i] - minprice;

        maxprofit = max(profit, maxprofit);
       }
       return maxprofit;

    }
};