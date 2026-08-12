class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        
        for(auto it : prerequisites) 
            adj[it[1]].push_back(it[0]);

        vector<int> inDegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto nei : adj[i]) 
                inDegree[nei]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++)
            if(inDegree[i] == 0)
                q.push(i);

        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for(auto nei : adj[node]) {
                inDegree[nei]--;
                if(inDegree[nei] == 0) 
                    q.push(nei);
            }
        }

        return (cnt == n);
    }
};