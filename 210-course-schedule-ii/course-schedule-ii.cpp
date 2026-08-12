class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);

        for(auto& it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        for(int i = 0; i < n; i++) {
            for(auto& it : adj[i])
                inDeg[it]++;
        }
        
        queue<int> q;

        for(int i = 0; i < n; i++) 
            if(inDeg[i] == 0)
                q.push(i);
        
        if(q.empty())
            return {};

        vector<int> ans;
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            ans.push_back(node);

            for(auto& it : adj[node]) {
                inDeg[it]--;

                if(inDeg[it] == 0)
                    q.push(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return (cnt == n) ? ans : vector<int>{};
    }
};