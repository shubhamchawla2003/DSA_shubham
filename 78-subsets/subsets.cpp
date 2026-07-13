class Solution {
public:
    void fun(int index, vector<int>& nums,
             vector<int>& temp, vector<vector<int>>& ans) {

        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // lena hai
        temp.push_back(nums[index]);
        fun(index + 1, nums, temp, ans);

        // BACKTRACK
        temp.pop_back();

        // nhi lena hai
        fun(index + 1, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        fun(0, nums, temp, ans);

        return ans;
    }
};