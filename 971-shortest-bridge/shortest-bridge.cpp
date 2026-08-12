class Solution {
public:
    int n;
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int, int>> q;

    void markContinent(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 2;
        q.push({i, j});

        for(auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                markContinent(ni, nj, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool found = false;

        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < n && !found; j++) 
                if(grid[i][j] == 1) {
                    found = true;
                    markContinent(i, j, grid);
                }
        }

        int dis = 0;

        while(!q.empty()) {
            int sz = q.size();
            dis++;

            for(int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(auto& d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && ny < n && nx < n && ny >= 0 && grid[nx][ny] != 2) {
                        if(grid[nx][ny] == 1)
                            return dis - 1;
                        if(grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }

        return 0;
    }
};