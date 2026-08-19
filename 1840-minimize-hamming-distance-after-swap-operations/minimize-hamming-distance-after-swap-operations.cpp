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
                    size[ultPar_v] += size[ultPar_u];
                    parent[ultPar_u] = ultPar_v;
                }
                else {
                    size[ultPar_u] += size[ultPar_v];
                    parent[ultPar_v] = ultPar_u;
                }
            }
    };

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DisJointSet djs(n);

        for(auto edg : allowedSwaps) {
            djs.unionBySize(edg[0], edg[1]);
        }

        int ans = 0;

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[djs.findUltParent(i)].push_back(i);
        
        for(auto [root, vec] : mp) {
            unordered_map<int, int> freq;
            
            for(auto idx : vec) 
                freq[source[idx]]++;
            
            for(auto idx : vec)
                freq[target[idx]]--;
            
            for(auto& [val, cnt] : freq) {
                if(cnt > 0)
                    ans += cnt;
            }
        }

        return ans;
    }
};