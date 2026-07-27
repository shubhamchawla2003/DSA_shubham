class Solution {
public:

    int fun(string a, string b, int i,int j, vector<vector<int>>& dp){

        if(i==a.length()) return 0;
        if(j==b.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(a[i]==b[j]){
            ans = 1 + fun(a,b,i+1,j+1,dp);
        }

        else{
            ans = max(fun(a,b,i+1,j,dp),fun(a,b,i,j+1,dp));
        }

        dp[i][j] = ans;

        return dp[i][j];
    }

    int funTabu(string a, string b){

        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));

        for(int i = a.length()-1;i>=0;i--){

            for(int j = b.length()-1;j>=0;j--){

                int ans = 0;

                if(a[i]==b[j]){
                   ans = 1 + dp[i+1][j+1];
                }

                else{
                    ans = max(dp[i+1][j],dp[i][j+1]);
                }

                dp[i][j] = ans;

            }
        }

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        
      //int count = 0;

     /* vector<int> vis(text1.length(),0);

        for (int i = 0; i < text2.length(); i++) {
            for (int j = 0; j < text1.length(); j++) {

                if (text2[i] == text1[j] && vis[j]==0) {
                    count++;
                    vis[j] = 1;
                }
            }
        }*/

       /* int last = -1;

        for (int i = 0; i < text2.length(); i++) {
          for (int j = last + 1; j < text1.length(); j++) {
            if (text2[i] == text1[j]) {
              count++;
              last = j;
              break;
            }
          }
        }

        return count;*/

        //using dp

       /*vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));

        return fun(text1,text2,0,0,dp);*/

        //using tabulation

        return funTabu(text1,text2);
    }
};