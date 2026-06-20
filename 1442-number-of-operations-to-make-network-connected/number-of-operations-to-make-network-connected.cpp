class Solution {
public:
    void helper(vector<vector<int>>& edges, vector<int>& vis, int idx) {
        vis[idx] = 1;

        for(int nei : edges[idx]) {
            if(vis[nei] == -1) 
                helper(edges, vis, nei);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size())
            return -1;

        vector<vector<int>> edges(n);
        int cnt = 0, total = 0;
        for(int i = 0; i < connections.size(); i++) {
            edges[connections[i][0]].push_back(connections[i][1]);
            edges[connections[i][1]].push_back(connections[i][0]);
            total++;
        }
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                helper(edges, vis, i);
                cnt++;
            }
        }

        return cnt - 1;
    }
};