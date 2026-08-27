class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<vector<int>> vis(n, vector<int>(n, 0));

        for(auto& pre : prerequisites) 
            adj[pre[0]].push_back(pre[1]);

        for(int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);
            vis[i][i] = 1;   

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto nei : adj[node]) {
                    if(!vis[i][nei]) {       
                        vis[i][nei] = 1;
                        q.push(nei);
                    }
                }
            }
        }

        vector<bool> ans;
        for(auto& que : queries)
            ans.push_back(vis[que[0]][que[1]]);

        return ans;
    }
};