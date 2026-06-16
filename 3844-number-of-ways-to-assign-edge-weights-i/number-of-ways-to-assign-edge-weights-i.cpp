class Solution {
public:
    int maxDepth = 0;
    const int MOD = 1e9 + 7;

    void dfs(int node, int parent, int depth, vector<vector<int>>& adj) {
        maxDepth = max(maxDepth, depth);

        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node, depth + 1, adj);
            }
        }
    }

    long long modpow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, -1, 0, adj);

        return modpow(2, maxDepth - 1, MOD);
    }
};