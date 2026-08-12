class Solution {
public:
    class DisJointSet {
        unordered_map<int, int> parent, size;
        public:
            void assignValues(int node) {
                if(parent.find(node) == parent.end()) {
                    parent[node] = node;
                    size[node] = 1;
                }
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

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisJointSet djs;
        const int OFFSET = 10001;

        for(auto edg : stones) {
            int x = edg[0];
            int y = edg[1] + OFFSET;

            djs.assignValues(x);
            djs.assignValues(y);
            djs.unionBySize(x, y);
        }

        unordered_set<int> distinct;
        for(auto edg : stones) {
            int ultPar = djs.findUltParent(edg[0]);
            distinct.insert(ultPar);
        }

        return n - distinct.size();
    }
};