class Solution {
public:
    unordered_map<char, int> ynode;
    vector<int> ans;

    void makeChanges(int node, vector<int>& parent, string& s, vector<vector<int>>& adj) {
        char ch = s[node];
        int prev = -1;

        if (ynode.count(ch)) {
            prev = ynode[ch];
            parent[node] = prev;      
        }
        ynode[ch] = node;

        for (int nei : adj[node])
            makeChanges(nei, parent, s, adj);

        if (prev == -1) ynode.erase(ch);
        else ynode[ch] = prev;
    }

    int findSize(int node, vector<vector<int>>& adj1) {
        int tmp = 1;
        for (int nei : adj1[node])
            tmp += findSize(nei, adj1);
        return ans[node] = tmp;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        ans.assign(n, 0);

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);   

        makeChanges(0, parent, s, adj);    

        vector<vector<int>> adj1(n);
        for (int i = 1; i < n; i++)
            adj1[parent[i]].push_back(i);  

        findSize(0, adj1);
        return ans;
    }
};