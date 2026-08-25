class Solution {
public:
    int nonObstacle = 0;
    int cnt = 0;
    int m, n, eni, enj;
    vector<vector<int>> vis;
    int di[4] = {0, -1, 0, 1};
    int dj[4] = {-1, 0, 1, 0};

    void helper(int i, int j,int curr,  vector<vector<int>>& grid) {
        if(eni == i && enj == j && curr == nonObstacle) {
            cnt++;
            return;
        }

        vis[i][j] = 1;    
        for(int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if(ni < m && nj < n && ni >= 0 && nj >= 0 && !vis[ni][nj] && grid[ni][nj] != -1) {
                
                helper(ni, nj, curr + 1, grid);
            }
        }

        vis[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int sti = -1, stj = -1;

        vis.assign(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == -1)
                    continue;
                if(grid[i][j] == 1) {
                    sti = i;
                    stj = j;
                }
                else if(grid[i][j] == 2) {
                    eni = i;
                    enj = j;
                }

                nonObstacle++;
            }
        }  

        helper(sti, stj, 1, grid);

        return cnt;
    }
};