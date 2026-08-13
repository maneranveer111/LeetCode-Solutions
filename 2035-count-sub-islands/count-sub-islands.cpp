class Solution {
public:
    int m, n;
    int cnt = 0;
    int dj[4] = {-1, 0, 1, 0};
    int di[4] = {0, -1, 0, 1};
    
    bool isSubIsland(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(grid1[i][j] == 0 && grid2[i][j] == 1)
            return false;

        if(grid2[i][j] == 2 || grid2[i][j] == 0)
            return false;

        bool res = true;
        grid2[i][j] = 2;            
                
        for(int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid2[ni][nj] == 1) {
                if(!isSubIsland(ni, nj, grid1, grid2))
                    res = false;
            }
        }

        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid2[i][j] || grid2[i][j] == 2)
                    continue;
                if(isSubIsland(i, j, grid1, grid2))
                    cnt++;
            }
        }

        return cnt;
    }
};

