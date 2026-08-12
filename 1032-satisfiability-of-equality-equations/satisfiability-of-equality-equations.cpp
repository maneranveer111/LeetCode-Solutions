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

                void unionBysize(int u, int v) {
                    int ultPar_u = findUltParent(u);
                    int ultPar_v = findUltParent(v);
                    
                    if(ultPar_u == ultPar_v)
                        return;
                    
                    if(size[ultPar_u] < size[ultPar_v]) {
                        size[ultPar_v] += size[ultPar_u];
                        parent[ultPar_u] = ultPar_v;
                    }
                    else{
                        size[ultPar_u] += size[ultPar_v];
                        parent[ultPar_v] = ultPar_u;
                    }
                }
    };

    bool equationsPossible(vector<string>& equations) {
        DisJointSet djs(26);

        for(auto equ : equations) {
            string str = equ.substr(1, 2);
            if(str == "!=")
                continue;

            int u = equ[0] - 'a';
            int v = equ[3] - 'a';
            
            djs.unionBysize(u, v);
        }    

        for(auto equ : equations) {
            string str = equ.substr(1, 2);
            if(str == "==")
                continue;

            int u = equ[0] - 'a';
            int v = equ[3] - 'a';

            int ultPar_u = djs.findUltParent(u);
            int ultPar_v = djs.findUltParent(v);

            if(str == "!=" && (ultPar_u == ultPar_v))
                return false;    
        }    

        return true;
    }
};