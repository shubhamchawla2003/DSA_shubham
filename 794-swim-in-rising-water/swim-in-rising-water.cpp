class Solution {
public:

    bool valid(int n,int m,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;

        return true;
    }

    int swimInWater(vector<vector<int>>& a) {
         int n = a.size();
        int m = a[0].size();

        vector<vector<int>> res(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};

        res[0][0] = a[0][0];
        pq.push({a[0][0],{0,0}});

        while(!pq.empty()){
           pair<int,pair<int,int>> p = pq.top();
           pq.pop();

           int time = p.first;
           int row = p.second.first;
           int col = p.second.second;

           if(row == n-1 && col == m-1) return time;

           if(time > res[row][col]) continue;

           for(int k = 0;k<4;k++){
            int r = row + x[k];
            int c = col + y[k];

            if(valid(n,m,r,c)){

                int new_time = max(a[r][c],time);

                if(new_time < res[r][c]){
                    res[r][c] = new_time;
                    pq.push({new_time,{r,c}});
                }
            }
           }
        }

        return res[n-1][m-1];
    }
};