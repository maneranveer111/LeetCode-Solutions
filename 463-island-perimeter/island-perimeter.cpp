class Solution {
public:
    vector<vector<int>> vis;
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int helper(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n )
            return 1;
        if(grid[i][j] == 0)
            return 1;

        vis[i][j] = 1;
        int peri = 0;
        
        for(int k = 0; k < 4; k++) {
            int ni = i + dy[k];
            int nj = j + dx[k];
            if(ni < m && nj < n && ni >= 0 && nj >= 0 && vis[ni][nj])
                continue;
            peri += helper(ni, nj, grid);
        }

        return peri;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !vis[i][j])
                    return helper(i, j, grid);
            }
        }

        return 0;
    }
};
