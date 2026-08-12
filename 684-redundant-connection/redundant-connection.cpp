class Solution {
public:
    class DisJointSet {
        vector<int> parent, size;
        public:
            DisJointSet(int n) {
                size.assign(n + 1, 1);
                parent.assign(n + 1, 0);
                for(int i = 0; i <= n; i++) 
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DisJointSet djs(n);

        for(auto edg : edges) {
            int u = edg[0];
            int v = edg[1];

            int ultPar_u = djs.findUltParent(u);
            int ultPar_v = djs.findUltParent(v);

            if(ultPar_u == ultPar_v) 
                return {u, v};
            
            djs.unionBySize(u, v);
        }
        
        return {};
    }
};