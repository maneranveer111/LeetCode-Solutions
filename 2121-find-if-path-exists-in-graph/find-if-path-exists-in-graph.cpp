class Solution {
public:
    vector<int> vis;

    bool helper(int node, int des, vector<vector<int>>& adj) {
        if(node == des)
            return true;
        vis[node] = 1;

        for(auto nei : adj[node]) {
            if(vis[nei])
                continue;
            if(helper(nei, des, adj))
                return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vis.assign(n, 0);

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }   

        return helper(source, destination, adj);
    }
};