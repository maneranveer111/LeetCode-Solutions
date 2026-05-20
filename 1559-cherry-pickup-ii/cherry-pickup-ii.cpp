class Solution {
public:
    int n, m;
    int dx[3] = {-1, 0, 1};

    int helper(int i, int j1, int j2, vector<vector<int>>& grid, 
        vector<vector<vector<int>>>& dp) {

        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return 0;
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        if(i == n - 1) {
            if(j1 == j2)
                return dp[i][j1][j2] = grid[i][j1];
            else 
                return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        int ans = INT_MIN;

        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                int a = 0;
                if(j1 == j2)
                    a = grid[i][j1] + helper(i + 1, j1 + dx[k], j2 + dx[l], grid, dp);
                else 
                    a = grid[i][j1] + grid[i][j2] +
                        helper(i + 1, j1 + dx[k], j2 + dx[l], grid, dp);
                ans = max(a, ans);  
            }
        }

        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return helper(0, 0, m - 1, grid, dp);
    }
};