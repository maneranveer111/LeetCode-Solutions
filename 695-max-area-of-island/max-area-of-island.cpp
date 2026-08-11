class Solution {
public:
    vector<vector<int>> vis;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int m, n;

    int helper(int i, int j, vector<vector<int>>& grid) {
        if(grid[i][j] == 0)
            return 0;
        vis[i][j] = 1;

        int area = 0;
        for(int k = 0; k < 4; k++) {
            int ni = i + dy[k];
            int nj = j + dx[k];

            if(ni < m && ni >= 0 && nj < n&& nj >= 0 && grid[ni][nj] == 1 && !vis[ni][nj])
                area += helper(ni, nj, grid);
        }

        return area + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size(); 
        vis.assign(m, vector<int>(n, 0));
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0 || vis[i][j])
                    continue;
                
                int area = helper(i, j, grid);
                ans = max(ans, area);
            }
        }

        return ans;
    }
};