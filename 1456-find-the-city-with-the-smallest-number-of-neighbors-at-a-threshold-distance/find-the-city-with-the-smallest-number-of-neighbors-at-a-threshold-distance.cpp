class Solution {
public:
    int m;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> dis;

    void findMinimumDis(int node) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[node][node] = 0;
        pq.push({0, node});

        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dis[node][u])
                continue;

            for(auto nei : adj[u]) {
                int nw = dis[node][u] + nei.second;

                if(nw < dis[node][nei.first]) {
                    dis[node][nei.first] = nw;
                    pq.push({nw, nei.first});
                }
            }
        }
        
    }   

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        adj.resize(n);
        dis.assign(n, vector<int>(n, 1e8));

        for(auto edg : edges) {
            adj[edg[0]].push_back({edg[1], edg[2]});
            adj[edg[1]].push_back({edg[0], edg[2]});
        }

        for(int i = 0; i < n; i++) {
            findMinimumDis(i);
        }
        int ans = 0;
        int minCnt = 1e7;

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(j != i && dis[i][j] <= distanceThreshold)
                    cnt++; 
            }

            if(cnt <= minCnt) {
                ans = i;
                minCnt = cnt;
            }
        }

        return ans;
    }
};