class Solution {
public:

    void fun(int idx, string digits,string temp, vector<string>& ans,vector<string>& mapping){

        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }

        string letters = mapping[digits[idx] - '0'];

        for (char ch : letters) {
            temp.push_back(ch);

            fun(idx + 1, digits, temp, ans, mapping);

            // Backtracking
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.size()==0) return ans;

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string temp;

        fun(0, digits, temp, ans, mapping);

        return ans;
    }
};