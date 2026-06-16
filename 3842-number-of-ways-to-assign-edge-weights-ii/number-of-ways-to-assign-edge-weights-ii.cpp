#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int LOG = 17;

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        
        // Build adjacency list (1-indexed)
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Binary lifting table and depth array
        vector<int> depth(n + 1, 0);
        vector<array<int, 17>> up(n + 1);
        for (int i = 0; i <= n; i++) up[i].fill(0);
        
        // BFS to compute depth and parent (up[node][0])
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        up[1][0] = 1; // root's parent is itself
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int nb : adj[node]) {
                if (!visited[nb]) {
                    visited[nb] = true;
                    depth[nb] = depth[node] + 1;
                    up[nb][0] = node;
                    q.push(nb);
                }
            }
        }
        
        // Fill binary lifting table
        for (int j = 1; j < LOG; j++)
            for (int i = 1; i <= n; i++)
                up[i][j] = up[up[i][j-1]][j-1];
        
        // LCA function
        auto lca = [&](int u, int v) -> int {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            // Bring u to same depth as v
            for (int j = 0; j < LOG; j++)
                if ((diff >> j) & 1)
                    u = up[u][j];
            if (u == v) return u;
            // Lift both until LCA
            for (int j = LOG - 1; j >= 0; j--)
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            return up[u][0];
        };
        
        // Precompute powers of 2
        vector<long long> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++)
            pow2[i] = pow2[i-1] * 2 % MOD;
        
        // Answer queries
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            int l = lca(u, v);
            int k = depth[u] + depth[v] - 2 * depth[l]; // path length
            
            if (k == 0)
                answer.push_back(0);
            else
                answer.push_back(pow2[k - 1]);
        }
        
        return answer;
    }
};