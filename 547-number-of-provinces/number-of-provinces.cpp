class Solution {
public:

    void fun(vector<vector<int>>& isConnected,
             int node,
             vector<bool>& visited) {

        visited[node] = true;

        for(int j = 0; j < isConnected.size(); j++) {

            if(isConnected[node][j] == 1 &&
               visited[j] == false) {

                fun(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> visited(n, false);

        int count = 0;

        for(int i = 0; i < n; i++) {

            if(visited[i] == false) {

                fun(isConnected, i, visited);

                count++;
            }
        }

        return count;
    }
};