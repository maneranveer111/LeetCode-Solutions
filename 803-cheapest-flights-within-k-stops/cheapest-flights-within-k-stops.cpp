class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        vector<int> minStops(n, INT_MAX);

        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();

            int cst = tmp[0], node = tmp[1], ck = tmp[2];

            if(node == dst)
                return cst;

            if(ck > k)
                continue;

            if(ck >= minStops[node])
                continue;

            minStops[node] = ck;

            for(auto it : adj[node]) {
                int nNd = it.first;
                int nPrc = it.second;
                pq.push({cst + nPrc, nNd, ck + 1});
            }
        }

        return -1;
    }
};