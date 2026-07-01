class Solution {
public:

    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool valid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;

        return true;
    }

    void dfs(vector<vector<char>>& a,int n,int m,int i,int j,vector<vector<bool>>& visited){
        visited[i][j]=1;

        for(int k = 0; k<4;k++){
            int row = i + x[k];
            int col = j + y[k];

            if(valid(row,col,n,m) && a[row][col]=='1' && visited[row][col]==0){
                dfs(a,n,m,row,col,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //int i,j;
        int count = 0;

        //create a visited 2d array in 0 values;
        vector<vector<bool>> visited(n);
        for(int i=0;i<n;i++){
            vector<bool> t(m,0);
            visited[i] = t;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    dfs(grid,n,m,i,j,visited);
                    count++;
                }
            }
        }

        return count;
    }
};