class Solution {
public:
    vector<vector<int>> ans;
    int n;
    vector<int> vis;

    void helper(int node, vector<int>& curr, vector<vector<int>>& graph) {
        if(node == n - 1) {
            curr.push_back(n - 1);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        vis[node] = 1;
        curr.push_back(node);

        for(auto& nei : graph[node]) {
            if(vis[nei] == -1) {
                helper(nei, curr, graph);
            }
        }

        vis[node] = -1;
        curr.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis.assign(n, -1);
        vector<int> curr;

        helper(0, curr, graph);

        return ans;
    }
};