class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);

        for(auto edg : edges) {
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);

            inDeg[edg[0]]++;
            inDeg[edg[1]]++;
        }   

        queue<int> q;

        for(int i = 0; i < n; i++)
            if(inDeg[i] == 1)
                q.push(i);

        int total = n;

        while(total > 2) {
            int sz = q.size();

            total -= sz;

            for(int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();

                for(auto nei : adj[node]) {
                    inDeg[nei]--;
                    
                    if(inDeg[nei] == 1)
                        q.push(nei);
                }
            }
        } 

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};