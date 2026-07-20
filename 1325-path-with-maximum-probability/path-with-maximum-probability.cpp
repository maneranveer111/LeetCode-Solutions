class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> prob(n, 0.0);
        priority_queue<pair<double,int>> pq;
        prob[start] = 1;

        pq.push({1.0, start});

        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            int node = tmp.second;
            double currProb = tmp.first;

            for(auto it : adj[node]) {
                double pro = currProb * it.second;

                if(pro > prob[it.first]) {
                    prob[it.first] = pro;
                    pq.push({pro, it.first});
                }
            }
        }

        return prob[end];
    }
};