class Solution {
public:

       // recursive solution
 /*   int fun(vector<int>& a,vector<int>& b, int idx, bool swapped){
        
        if(idx == a.size()) return 0;

        int prev_a = a[idx-1];
        int prev_b = b[idx-1];

        if (swapped == true){
            swap(prev_a, prev_b);
        } 

        int ans = INT_MAX;

        //not swaped
        if(a[idx] > prev_a && b[idx] > prev_b){
             ans = fun(a,b,idx+1,false);
        }

        //swaped
        if(a[idx] > prev_b && b[idx] > prev_a){
            ans = min(ans,1+fun(a,b,idx+1,true));
        }

        return ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        return fun(nums1,nums2,1,false);
    } */

     // dp solution
    int fun(vector<int>& a,vector<int>& b, int idx, bool swapped,vector<vector<int>>& dp){
        
        if(idx == a.size()) return 0;

        if(dp[idx][swapped] != -1) return dp[idx][swapped];

        int prev_a = a[idx-1];
        int prev_b = b[idx-1];

        if (swapped == true){
            swap(prev_a, prev_b);
        } 

        int ans = INT_MAX;

        //not swaped
        if(a[idx] > prev_a && b[idx] > prev_b){
             ans = fun(a,b,idx+1,false,dp);
        }

        //swaped
        if(a[idx] > prev_b && b[idx] > prev_a){
            ans = min(ans,1+fun(a,b,idx+1,true,dp));
        }

        dp[idx][swapped] = ans;

        return dp[idx][swapped];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return fun(nums1,nums2,1,false,dp);
    }
};