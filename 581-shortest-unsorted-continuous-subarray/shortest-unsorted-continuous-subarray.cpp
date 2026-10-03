class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

       /* int n = nums.size();

        vector<int> temp = nums;

        sort(temp.begin(),temp.end());

        int i = 0;
        int j = n-1;

        int ans = 0;

        while(i<n && nums[i]==temp[i]) i++;

        while(j>=0 && nums[j]==temp[j]) j--;

        if(i>j) return 0;
        
        return j-i+1; */


        int n = nums.size();

        int left = 0;
        int right = n - 1;

        // Find first decreasing position from left
        while(left < n-1 && nums[left] <= nums[left+1]) left++;

        // Already sorted
        if(left == n-1) return 0;

        // Find first decreasing position from right
        while(right > 0 && nums[right] >= nums[right-1]){
            right--;
        }

        int min_num = INT_MAX;
        int max_num = INT_MIN;

        for(int i=left;i<=right;i++){
            min_num = min(min_num,nums[i]);
            max_num = max(max_num,nums[i]);
        }

        while(left > 0 && nums[left-1] > min_num) left--;

        while(right < n-1 && nums[right+1] < max_num) right++;
        

        return right-left+1;
    }
};