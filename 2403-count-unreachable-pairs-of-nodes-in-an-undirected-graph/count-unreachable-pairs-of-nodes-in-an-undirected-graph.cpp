class Solution {
public:
    vector<int> vis;

    long long helper(int node, vector<vector<int>>& adj) {
        int cnt = 0;
        if(vis[node])
            return 0;
        vis[node] = 1;
        for(auto nei : adj[node]) {
            if(!vis[nei]) {
                cnt += helper(nei, adj);
            }
        }

        return 1 + cnt;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vis.assign(n, 0);

        for(auto edg : edges) {
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }
        
        vector<long long> numInCompo;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                long long cnt = helper(i, adj);
                numInCompo.push_back(cnt);
            }
        }

        if(numInCompo.size() == 1)
            return 0;

        sort(numInCompo.begin(), numInCompo.end());
        long long sum = 0;
        long long ans = 0;

        for(int i = 0; i < numInCompo.size(); i++) {
            ans += sum * numInCompo[i];
            sum += numInCompo[i];    
        } 

        return ans;
    }
};