class Solution {
public:

    // using iterative method
   /* int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;

        int a = 1;
        int b = 2;

        int c = 0;

        for(int i=3;i<=n;i++){
            c = a+b;
            a = b;
            b = c;
        }

        return c;

    }*/

    //using recursion
   /* int climbStairs(int n){

        if(n<=2) return n;

        int ans = climbStairs(n-1)+climbStairs(n-2);

        return ans;
    }*/

    // using dp

    unordered_map<int,int> dp;

    int climbStairs(int n){

        if(n<=2) return n;

        if(dp.find(n) != dp.end()){
            return dp[n];
        }

        int ans = climbStairs(n-1)+climbStairs(n-2);

        dp[n] = ans;

        return ans;
    }
};