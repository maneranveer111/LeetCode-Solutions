class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++) {
            if(vis[i] != -1)
                continue;
            
            queue<pair<int, int>> q;
            q.push({i, 1});
            vis[i] = 1;

            while(!q.empty()) {
                int node = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i = 0; i < graph[node].size(); i++) {
                    if(vis[graph[node][i]] != -1 && vis[graph[node][i]] == col)
                        return false;
                    if(vis[graph[node][i]] != -1)
                        continue;

                    if(col == 1) {
                        q.push({graph[node][i], 0});
                        vis[graph[node][i]] = 0;
                    }
                    else {
                        q.push({graph[node][i], 1});
                        vis[graph[node][i]] = 1;
                    }
                }
            }
        }

        return true;
    }
};