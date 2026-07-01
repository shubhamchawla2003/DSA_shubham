class Solution {
public:

    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool valid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;

        return true;
    }

    int dfs(vector<vector<int>>& a,int n,int m,int i,int j,vector<vector<bool>>& visited){
        visited[i][j] = 1;// means true;

        int area = 1;
        
        for(int k = 0; k<4; k++){
            int row = i + x[k];
            int col = j + y[k];

            if(valid(row,col,n,m) && a[row][col]==1 && visited[row][col]==0){
               area += dfs(a,n,m,row,col,visited);
            }
        }

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

       int n = grid.size();
       int m = grid[0].size();

       int max_area = 0;

       //create a visited 2D array

       vector<vector<bool>> visited(n, vector<bool>(m,0));

       for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(grid[i][j]==1 && visited[i][j]==0){
               int area = dfs(grid,n,m,i,j,visited);

               max_area = max(area,max_area);
            }

        }
       }

       return max_area;

    }
};