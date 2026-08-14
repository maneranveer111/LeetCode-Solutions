class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dis(n + 1, INT_MAX);

        for(auto edg : times) {
            adj[edg[0]].push_back({edg[1], edg[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dis[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            int node = tmp.second;
            int dist = tmp.first;

            for(auto nei : adj[node]) {
                int wt = nei.second;
                int poi = nei.first;

                if(dist + wt < dis[poi]) {
                    dis[poi] = dist + wt;
                    pq.push({dis[poi], poi});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(dis[i] == INT_MAX)
                return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};