class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int>& check, vector<vector<int>>& graph) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto& nei : graph[node]) {
            if(vis[nei] == -1) {
                if(dfs(nei, vis, pathVis, check, graph))  {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[nei] == 1) {
                check[node] = 0;
                return true;
            }
        }

        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, -1), pathVis(v, -1), check(v, 0);
        vector<int> ans;
        
        for(int i = 0; i < v; i++) {
            if(vis[i] != -1)
                continue;

            dfs(i, vis, pathVis, check, graph);
        }

        for(int i = 0; i < v; i++)
            if(check[i] == 1)
                ans.push_back(i);
            
        return ans;
    }
};