class Solution {
public:
    int fun(vector<int>& nums, int idx, int prev, vector<vector<int>>& dp) {

        if (idx == nums.size())
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int notTake = fun(nums, idx + 1, prev, dp);

        int take = 0;

        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + fun(nums, idx + 1, idx, dp);
        }

        return dp[idx][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return fun(nums, 0, -1, dp);
    }
};