class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> a(n+1);
        
        for(int i = 0;i<times.size();i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            
            a[s].push_back({d,w});
           // a[d].push_back({s,w});
            
        }
        
        //create a min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        
        pq.push({0,k});
        
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            
            int d = p.first;
            int node = p.second;
            
            if(d > dist[node]) continue;
            
            for(int i = 0;i<a[node].size();i++){
                int neigh = a[node][i].first;
                int weight = a[node][i].second;
                
                if(d + weight < dist[neigh]){
                    dist[neigh] = d + weight;
                    pq.push({d+weight,neigh});
                }
            }
        }
        
        int ans = 0;

        for(int i = 1;i<=n;i++){

            if(dist[i] == INT_MAX) return -1;

            ans = max(ans,dist[i]);
        }

        return ans;
    }
};