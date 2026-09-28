class Solution {
public:
    class DisJointSet {
    public:
        vector<int> parent, size;

        DisJointSet(int n) {
            parent.resize(n);
            size.assign(n, 1);

            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findUltParent(int u) {
            if(parent[u] == u)
                return u;
            
            return parent[u] = findUltParent(parent[u]);
        }

        void unionBySize(int u, int v) {
            int ultPar_u = findUltParent(u);
            int ultPar_v = findUltParent(v);

            if(ultPar_u == ultPar_v)
                return;
            
            if(size[ultPar_u] < size[ultPar_v]) {
                parent[ultPar_u] = ultPar_v;
                size[ultPar_v] += size[ultPar_u];
                size[ultPar_u] = size[ultPar_v]; 
            }
            else {
                parent[ultPar_v] = ultPar_u;      
                size[ultPar_u] += size[ultPar_v];
            }
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        for(int i = 0; i < n; i++) {
            int xi = points[i][0];
            int yi = points[i][1];
            
            for(int j = i + 1; j < n; j++) {
                int xj = points[j][0];
                int yj = points[j][1];

                int dis = abs(xi - xj) + abs(yi - yj);
                edges.push_back({i, j, dis});
                // adj[j].push_back({i, dis});
            }
        }

        sort(edges.begin(), edges.end(), [&](auto& a, auto& b) {
            return a[2] < b[2];
        });

        DisJointSet djs(n);
        int ans = 0;

        for(auto edg : edges) {
            int u = edg[0], v = edg[1], wt = edg[2];

            int ultPar_u = djs.findUltParent(u);
            int ultPar_v = djs.findUltParent(v);

            if(ultPar_u != ultPar_v) {
                ans += wt;
                djs.unionBySize(u, v);
            }
        }

        return ans;
    }
};
