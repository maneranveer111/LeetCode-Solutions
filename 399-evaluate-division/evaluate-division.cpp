class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_set<string> vis;
    bool isFound = false;
    double helper(string node, string tar) {
        if(node == tar) {
            isFound = true;
            return 1.0;
        }

        vis.insert(node);
        
        for(auto nei : adj[node]) {
            if(!vis.count(nei.first)) {
                double curr = helper(nei.first, tar);
                if(isFound) {
                    vis.erase(node);
                    curr *= nei.second;
                    return curr;
                }
            }
        }

        vis.erase(node);
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int i = 0;
        for(auto equ : equations) {
            string u = equ[0];
            string v = equ[1];

            double u_v = values[i];
            double v_u = 1.0 / u_v;
            i++;
            adj[u].push_back({v, u_v});
            adj[v].push_back({u, v_u});
        }

        vector<double> ans;

        for(auto que : queries) {
            string u = que[0];
            string v = que[1];

            if(adj.find(u) == adj.end() || adj.find(v) == adj.end()) {
                ans.push_back(-1.0);
                continue;
            }

            isFound = false;
            vis.clear();

            double tmp = helper(u, v);
            ans.push_back(tmp);
        }

        return ans;
    }
};