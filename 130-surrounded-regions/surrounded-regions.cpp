class Solution {
public:

    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};

    bool valid(int n,int m,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;

        return true;
    }

    void dfs(vector<vector<char>>& a,int n,int m,int i,int j){

        a[i][j] = '#';

        for(int k = 0;k<4;k++){

            int row = i + x[k];
            int col = j + y[k];

            if(valid(n,m,row,col) && a[row][col] == 'O'){
                dfs(a,n,m,row,col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        //O in first row
        for(int j = 0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(board,n,m,0,j);
            }
        }

        //O in last row
        for(int j = 0;j<m;j++){
            if(board[n-1][j]=='O'){
                dfs(board,n,m,n-1,j);
            }
        }

        //O in first col
        for(int i = 0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,n,m,i,0);
            }
        }

        //O in last col
        for(int i = 0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(board,n,m,i,m-1);
            }
        }

        //print the new matrix

        for(int i = 0;i<n;i++){

            for(int j=0;j<m;j++){

                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }

                else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};