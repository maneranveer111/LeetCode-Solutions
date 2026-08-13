class Solution {
public:
    int m, n;
    int di[4] = {0, -1, 0, 1};
    int dj[4] = {-1, 0, 1, 0};
    
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& vis) {
        vis[i][j] = true;

        for(int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && !vis[ni][nj] 
                && heights[ni][nj] >= heights[i][j]) 
                    dfs(ni, nj, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> alt(m, vector<int>(n, false));        
        vector<vector<int>> pac(m, vector<int>(n, false));        
    
        for(int i = 0; i < m; i++)
            dfs(i, 0, heights, pac);
        
        for(int j = 0; j < n; j++)
            dfs(0, j, heights, pac);
        
        for(int i = 0; i < m; i++)
            dfs(i, n - 1, heights, alt);
        
        for(int j = 0; j < n; j++)
            dfs(m - 1, j, heights, alt);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(alt[i][j] && pac[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};