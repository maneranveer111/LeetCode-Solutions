class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent, size;

        UnionFind(int n) {
            size.assign(n, 1);
            parent.resize(n);

            for(int i = 0; i < n; i++)
                parent[i] = i;   
        }

        int findUltParent(int node) {
            if(parent[node] == node)
                return node;
            
            return parent[node] = findUltParent(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ultPar_u = findUltParent(u);
            int ultPar_v = findUltParent(v);
            
            if(ultPar_u == ultPar_v)
                return;
            
            if(size[ultPar_u] < size[ultPar_v]) {
                parent[ultPar_u] = ultPar_v;
                size[ultPar_v] += size[ultPar_u];
            }
            else{
                parent[ultPar_v] = ultPar_u;
                size[ultPar_u] += size[ultPar_v];
            }
        }
    };

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n);

        for(auto edg : edges) {
            int u = edg[0];
            int v = edg[1];

            uf.unionBySize(u, v);
        }

        vector<int> compAnd(n, -1);
        for (auto& edg : edges) {
            int root = uf.findUltParent(edg[0]);
            compAnd[root] &= edg[2];
        }

        vector<int> ans;

        for(auto que : query) {
            int u = que[0];
            int v = que[1];

            int ult_u = uf.findUltParent(u);
            int ult_v = uf.findUltParent(v);

            if(ult_u != ult_v) {
                ans.push_back(-1);
                continue;
            }

            ans.push_back(compAnd[ult_u]);
        }

        return ans;
    }
};