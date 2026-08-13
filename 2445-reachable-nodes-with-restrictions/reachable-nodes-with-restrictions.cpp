class Solution {
public:
    class DisJointSet {
        vector<int> parent, size;
        public:
            DisJointSet(int n) {
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
                else {
                    parent[ultPar_v] = ultPar_u;
                    size[ultPar_u] += size[ultPar_v];
                }   
            }
    };

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        DisJointSet djs(n);

        unordered_set<int> st;
        for(int x : restricted)
            st.insert(x);

        for(auto edg : edges) {
            int u = edg[0];
            int v = edg[1];

            if(st.count(u) || st.count(v))
                continue;
            djs.unionBySize(u, v);
        }    
        
        int ultPar_0 = djs.findUltParent(0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int ultPar_i = djs.findUltParent(i);
            if(ultPar_i == ultPar_0)
                cnt++;
        }

        return cnt;
    }
};