class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // int n = edges.size() + 1;
        // vector<vector<int>> adj(n + 1);

        // for(auto edg : edges) {
        //     adj[edg[0]].push_back(edg[1]);
        //     adj[edg[1]].push_back(edg[0]);
        // }   

        // for(int i = 1; i <= n; i++) 
        //     if(adj[i].size() == n- 1)
        //         return i;

        // return -1;

        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
    }
};