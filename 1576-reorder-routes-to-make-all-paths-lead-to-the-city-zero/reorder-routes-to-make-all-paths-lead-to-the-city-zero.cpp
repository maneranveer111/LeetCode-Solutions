class Solution {
public:
    vector<int> vis;
    set<pair<int, int>> st;

    int ans = 0;

    void dfs(int u, vector<vector<int>>& adj, vector<vector<int>>& connections) {
        vis[u] = 1;

        for(auto nei : adj[u]) {
            if(vis[nei])
                continue; 
            if(st.find({u, nei}) != st.end())
                ans++;
            dfs(nei, adj, connections);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vis.assign(n, 0);
        vector<vector<int>> adj(n);

        for(auto con : connections) {
            st.insert({con[0], con[1]});
        }

        for(auto con : connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }

        dfs(0, adj, connections);
        
        return ans;
    }
};