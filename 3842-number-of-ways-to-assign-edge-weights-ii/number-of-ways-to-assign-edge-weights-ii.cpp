class Solution {
public:
    const int MOD = 1e9 + 7;
    unordered_map<int, unordered_map<int, int>> memo; // memo[u][v] = dist
    vector<int> dep;
    vector<int> parent;
    vector<vector<int>> up; // binary lifting table
    int LOG = 17;

    void dfs(int node, int par, int d, vector<vector<int>>& adj) {
        dep[node] = d;
        up[node][0] = par;
        for (int i = 1; i < LOG; i++)
            up[node][i] = up[up[node][i-1]][i-1];
        
        for (int nei : adj[node]) {
            if (nei != par)
                dfs(nei, node, d + 1, adj);
        }
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int diff = dep[u] - dep[v];
        
        // bring u and v to same depth
        for (int i = 0; i < LOG; i++)
            if ((diff >> i) & 1)
                u = up[u][i];
        
        if (u == v) return u;
        
        // lift both until LCA
        for (int i = LOG - 1; i >= 0; i--)
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        
        return up[u][0];
    }

    // long long modpow(long long base, long long exp, long long mod) {
    //     long long result = 1;
    //     while (exp > 0) {
    //         if (exp % 2 == 1)
    //             result = result * base % mod;
    //         base = base * base % mod;
    //         exp /= 2;
    //     }
    //     return result;
    // }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        dep.resize(n + 1);
        up.assign(n + 1, vector<int>(LOG, 0));

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 0, 0, adj); // precompute depths + binary lifting
        vector<long long> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++)
            pow2[i] = pow2[i-1] * 2 % MOD;

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0], v = queries[i][1];

            if (u == v) { ans[i] = 0; continue; }

            // memoize dist(u,v)
            if (!memo[u].count(v)) {
                int ancestor = lca(u, v);
                int dist = dep[u] + dep[v] - 2 * dep[ancestor];
                memo[u][v] = memo[v][u] = dist;
            }

            ans[i] = pow2[memo[u][v] - 1];
        }
        return ans;
    }
};