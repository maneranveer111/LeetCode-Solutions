class Solution {
public:
    const int MOD = 1e9 + 7;
    const int LOG =    17;

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> depth(n + 1, 0);
        vector<array<int, 17>> up(n + 1);
        for(int i = 0; i <= n; i++) 
            up[i].fill(0);

        vector<bool> vis(n + 1, false);
        queue<int> q;
        
        q.push(1);
        vis[1] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nei : adj[node]) {
                if(!vis[nei]) {
                    vis[nei] = true;
                    depth[nei] = depth[node] + 1;
                    up[nei][0] = node;
                    q.push(nei);
                }
            }
        }

        for(int j = 1; j < LOG; j++)
            for(int i = 1; i <= n; i++)
                up[i][j] = up[up[i][j - 1]][j - 1];

        auto lca = [&](int u, int v) -> int {
            
            if(depth[u] < depth[v]) 
                swap(u, v);
            
            int diff = depth[u] - depth[v];
            for(int i = 0; i < 17; i++) {
                if((diff >> i) & 1)
                    u = up[u][i];
            }

            if(u == v)  
                return u;
            
            for(int j = LOG - 1; j >= 0; j--) {
                if(up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];

        };

        vector<long long> pow2(n + 1);
        pow2[0] = 1;
        for(int i = 1; i <= n; i++)
            pow2[i] = pow2[i - 1] * 2 % MOD;

        vector<int> ans;
        ans.reserve(queries.size());

        for(auto& query : queries) {
            int u = query[0], v = query[1];

            int l = lca(u, v);
            int k = depth[u] + depth[v] - 2 * depth[l];

            if(k == 0)
                ans.push_back(0);
            else 
                ans.push_back(pow2[k - 1] % MOD);
        }

        return ans;
    }
};