class Solution {
public:

    bool res = true;

    void dfs(vector<vector<int>>& a,int node,int c,vector<int>& colors){

        colors[node] = c;

        for(int i=0;i<a[node].size();i++){
            int neigh = a[node][i];

            if(colors[neigh] != -1 && colors[neigh] == c) {
                res = false;
            }

            else if(colors[neigh] == -1){
                dfs(a,neigh,1-c,colors);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<int> colors(n,-1);

        for(int i=0;i<n;i++){
            if(colors[i] == -1){
                dfs(graph,i,0,colors);
            }
        }

        return res;
    }
};