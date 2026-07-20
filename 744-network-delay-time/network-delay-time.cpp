class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dis(n + 1, INT_MAX);

        for(auto arr : times) {
            adj[arr[0]].push_back({arr[1], arr[2]});
        } 

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        dis[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for(auto it : adj[node]) {
                int nei = it.first;
                int ndis = it.second;

                if(dist + ndis < dis[nei]) {
                    dis[nei] = dist + ndis;
                    pq.push({dist + ndis, nei});
                }
            }
        }

        int maxi = INT_MIN;
        
        for(int i = 1; i <= n; i++) {
            if(dis[i] == INT_MAX)
                return -1;
            maxi = max(maxi, dis[i]);
        } 

        return maxi;
    }
};