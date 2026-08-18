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
                
                if(size[ultPar_v] > size[ultPar_u]) {
                    size[ultPar_v] += size[ultPar_u];
                    parent[ultPar_u] = ultPar_v;
                }
                else{
                    size[ultPar_u] += size[ultPar_v];
                    parent[ultPar_v] = ultPar_u; 
                }
            }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DisJointSet djs(26);

        for(int i = 0; i < n; i++) {
            char ch1 = s1[i];
            char ch2 = s2[i];

            djs.unionBySize((ch1 - 'a'), (ch2 - 'a'));
        }

        unordered_map<int, char> mp;

        for(int i = 0; i < 26; i++) {
            int ultPar_i = djs.findUltParent(i);
            char ch = i + 'a';

            if(!mp.count(ultPar_i))
                mp[ultPar_i] = ch;
            else {
                char c = mp[ultPar_i];
                if(ch < c)
                    mp[ultPar_i] = ch;
            }
        }

        string ans = "";
        for(char ch : baseStr) {
            int i = ch - 'a';
            int ultPar_i = djs.findUltParent(i);
            char nch = mp[ultPar_i];
            ans.push_back(nch);
        }

        return ans;
    }
};