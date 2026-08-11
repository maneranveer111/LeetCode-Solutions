class Solution {
public:
    vector<vector<int>> vis;
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    void helper(int i, int j, vector<vector<int>>& grid) {
        vis[i][j] = 1;

        for(int d = 0; d < 4; d++) {
            int ni = i + dy[d];
            int nj = j + dx[d];

            if(ni >= 0 && nj >= 0 && nj < n && ni < m && !vis[ni][nj] && grid[ni][nj] == 0)
                helper(ni, nj, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if(!vis[i][j] && !grid[i][j])
                        helper(i, j, grid);
                } 
            }
        }

        int cnt = 0;
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(!vis[i][j] && !grid[i][j]) {
                    helper(i, j, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};