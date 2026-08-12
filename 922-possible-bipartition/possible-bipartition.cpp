class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < dislikes.size(); i++) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> vis(n + 1, -1);
        for(int i = 1; i <= n; i++) {
            if(vis[i] != -1)
                continue;
            
            queue<pair<int, int>> q;
            q.push({i, 1});
            vis[i] = 1;

            while(!q.empty()) {
                int node = q.front().first;
                int col = q.front().second;   
                q.pop();

                for(auto nei : adj[node]) {
                    if(vis[nei] != -1 && vis[nei] == col)
                        return false;
                    if(vis[nei] != -1)
                        continue;
                    
                    if(col == 1) {
                        q.push({nei, 0});
                        vis[nei] = 0;
                    }
                    else {
                        q.push({nei, 1});
                        vis[nei] = 1;
                    }
                }
            }
        }

        return true;
    }
};