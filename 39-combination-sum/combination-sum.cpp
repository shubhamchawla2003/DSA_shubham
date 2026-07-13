class Solution {
public:

    void fun(int idx,vector<int>& arr,int x,vector<int>& temp,vector<vector<int>>& ans){

        if(idx == arr.size()){
            if(x==0){
                ans.push_back(temp);
            }

            return;
        }

        if(arr[idx]<=x){

            temp.push_back(arr[idx]);
            
            fun(idx,arr,x-arr[idx],temp,ans);

            temp.pop_back();
        }

        fun(idx+1,arr,x,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        fun(0,candidates,target,temp,ans);

        return ans;
    }
};