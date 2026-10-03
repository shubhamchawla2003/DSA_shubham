class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp = nums;

        sort(temp.begin(),temp.end());

        int i = 0;
        int j = n-1;

        int ans = 0;

        while(i<n && nums[i]==temp[i]) i++;

        while(j>=0 && nums[j]==temp[j]) j--;

        if(i>j) return 0;
        
        return j-i+1;
    }
};