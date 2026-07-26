class Solution {
public:
   /* int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int profit = INT_MIN;

        for(int i=n-1;i>=0;i--){
          for(int j= i-1;j>=0;j--){
            int diff = prices[i]-prices[j];

            profit = max(profit,diff);
          }
        }

        if(profit<0) return 0;

        return profit;
    } */

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int mini = prices[0];

        int profit = INT_MIN;

        for(int i=1;i<n;i++){
            int diff = prices[i]-mini;

            profit = max(profit,diff);

            mini = min(mini,prices[i]);
        }

        if(profit<0) return 0;

        return profit;
    }
};