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

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        DisJointSet djs(m * n);

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};            

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > 0)
                        djs.unionBySize(i * n + j, ni * n + nj);
                }
            }
        }

        unordered_map<long long, long long> mp;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    continue;
                int key = i * n + j;

                int par = djs.findUltParent(key);

                mp[par] += grid[i][j];
            }
        }

        int cnt = 0;

        for(auto [par, sum] : mp)
            if(sum % k == 0)
                cnt++;
        
        return cnt;
    }
};