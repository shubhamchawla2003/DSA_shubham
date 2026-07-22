class Solution {
public:

   /* int fun(int i,int n, vector<int>& a){
        if(i>=n) return 0;

        return a[i] + min(fun(i+1,n,a),fun(i+2,n,a));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int ans = min(fun(0,n,cost),fun(1,n,cost));

        return ans;
    } */

     int fun(int i,int n, vector<int>& a,vector<int>& dp){
        if(i>=n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = a[i] + min(fun(i+1,n,a,dp),fun(i+2,n,a,dp));

        dp[i] = ans;

        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+1,-1);

        int ans = min(fun(0,n,cost,dp),fun(1,n,cost,dp));

        return ans;
    }
};