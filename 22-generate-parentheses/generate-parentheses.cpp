class Solution {
public:

    void fun(int n,vector<string>& ans,string temp, int open,int close){

        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }

        if(open + 1 <= n){
            temp.push_back('(');
            fun(n,ans,temp,open+1,close);
            temp.pop_back();
        }

        if(close + 1 <= n && close+1<=open){
            temp.push_back(')');
            fun(n,ans,temp,open,close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        fun(n,ans,temp,0,0);

        return ans;
    }
};