class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto edg : redEdges) {
            adj[edg[0]].push_back({edg[1], 0});
        }

        for(auto edg : blueEdges) {
            adj[edg[0]].push_back({edg[1], 1});
        }

        queue<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(2, 1e7));
        q.push({0, 0});
        q.push({0, 1});
        dis[0][0] = 0;
        dis[0][1] = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto nei : adj[node]) {
                if(nei.second != col && dis[nei.first][nei.second] == 1e7) {
                    dis[nei.first][nei.second] = dis[node][col] + 1;
                    q.push({nei.first, nei.second});
                }
            }
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = min(dis[i][0], dis[i][1]);
            if(ans[i] == 1e7)
                ans[i] = -1;
        }

        return ans;
    }
};