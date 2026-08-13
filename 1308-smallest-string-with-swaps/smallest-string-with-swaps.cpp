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
                
                return  parent[node] = findUltParent(parent[node]);
            }

            void unionBySize(int u, int v) {
                int ultPar_u = findUltParent(u);
                int ultPar_v = findUltParent(v);
                
                if(ultPar_u == ultPar_v)
                    return;
                
                if(size[ultPar_u] < size[ultPar_v]) {
                    size[ultPar_v] += size[ultPar_u];
                    parent[ultPar_u] = ultPar_v;
                }
                else {
                    size[ultPar_u] += size[ultPar_v];
                    parent[ultPar_v] = ultPar_u;
                }
            }
    };

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DisJointSet djs(n);

        for(auto pai : pairs) {
            djs.unionBySize(pai[0], pai[1]);
        }    

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            int ultPar = djs.findUltParent(i);
            mp[ultPar].push_back(i);
        }

        unordered_map<int, string> mp1;

        for(auto [ultpar, vec] : mp) {
            string str = "";
            for(int i = 0; i < vec.size(); i++)
                str.push_back(s[vec[i]]);
            sort(str.begin(), str.end());
            mp1[ultpar] = str;
        }

        string ans = ""; 
        unordered_map<int, int> pointer;

        for(int i = 0; i < n; i++) {
            int ultPar = djs.findUltParent(i);
            if(!pointer.count(ultPar)) 
                pointer[ultPar] = 0;
            ans.push_back(mp1[ultPar][pointer[ultPar]]);
            pointer[ultPar]++;
        }

        return ans;
    }
};