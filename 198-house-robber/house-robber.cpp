class Solution {
public:
    
    // using recursion
    /*int fun(vector<int>& a,int n,int i,int free){

        if(i==n) return 0;

        if(free==0) return fun(a,n,i+1,1);
        
        //chori kar li to next ghar ka free value 0 kar diya
        int c1 = a[i]+fun(a,n,i+1,0);
        
        //chori nhi kari
        int c2 = fun(a,n,i+1,1);

        int ans = max(c1,c2);

        return ans;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        return fun(nums,n,0,1);
        
    }*/
    
    //using dp
   /* int fun(vector<int>& a,int n,int i,int free,vector<vector<int>>& dp){

        if(i==n) return 0;

        if(dp[i][free] != -1) return dp[i][free];

        if(free==0){
            return dp[i][free] = fun(a,n,i+1,1,dp);
        }
        
        //chori kar li to next ghar ka free value 0 kar diya
        int c1 = a[i]+fun(a,n,i+1,0,dp);
        
        //chori nhi kari
        int c2 = fun(a,n,i+1,1,dp);

        int ans = max(c1,c2);

        dp[i][free] = ans;

        return ans;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        // 2 because free value sirf 2 hi hai ya to 0 ya 1
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return fun(nums,n,0,1,dp);
        
    }*/

    int fun(vector<int>& nums,int n,int i,vector<int>& dp){
    if(i==n-1) return nums[n-1];

    if(i>=n) return 0;

    if(dp[i] != -1) return dp[i];

    int lena_hai = fun(nums,n,i+2,dp) + nums[i];

    int nhi_lena_hai = fun(nums,n,i+1,dp);

    int ans = max(lena_hai,nhi_lena_hai);

    dp[i] = ans;

    return ans;
}
int rob(vector<int> &nums){
    // Write your code here.

    int n = nums.size();

    vector<int> dp(n+1,-1);

    return fun(nums,n,0,dp);
}
};