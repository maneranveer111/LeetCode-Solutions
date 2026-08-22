class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for(auto edg : paths) {
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }

        vector<int> vis(n + 1, 0);
        vector<int> ans(n);

        for(int i = 1; i <= n; i++) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()) {
                int node = q.front(); 
                q.pop();

                set<int> used;
                for (auto nei : adj[node]) {
                    if (ans[nei - 1] != 0)
                        used.insert(ans[nei - 1]);
                }

                for (int c = 1; c <= 4; c++) {
                    if (used.find(c) == used.end()) {
                        ans[node - 1] = c;
                        break;
                    }
                }

                for(auto nei : adj[node]) {
                    if(vis[nei])
                        continue;
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }

        return ans;
    }
};