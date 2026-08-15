class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adj(n);

        for(auto edg : edges) {
            adj[edg[0]].push_back({edg[1], edg[2]});
            adj[edg[1]].push_back({edg[0], edg[2]});
        }

        vector<int> minTime(n, INT_MAX), minCost(n, INT_MAX);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        minCost[0] = passingFees[0];
        minTime[0] = 0;
        pq.push({passingFees[0], 0, 0});

        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();

            int cst = tmp[0], node = tmp[2], time = tmp[1];

            if(time > maxTime)
                continue;
            
            if(cst > minCost[node] && time > minTime[node])
                continue;

            if(node == n - 1)   
                return cst;

            for(auto nei : adj[node]) {
                int newTime = time + nei.second;
                int newCst = cst + passingFees[nei.first];

                if(newTime > maxTime)
                    continue;
                
                if(newCst < minCost[nei.first] || newTime < minTime[nei.first]) {
                    minCost[nei.first] = newCst;
                    minTime[nei.first] = newTime;
                    pq.push({newCst, newTime, nei.first});
                }
            }
        }

        return -1;
    }
};