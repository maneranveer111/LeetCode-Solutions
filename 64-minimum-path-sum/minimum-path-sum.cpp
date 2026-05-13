class Solution {
public:
    int m, n;

    int minSum(vector<vector<int>>& grid, vector<vector<int>>& dp, 
            int i, int j) {
        
        if(i == n - 1 && j == m - 1)
            return grid[i][j] ;

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = (i + 1 < n) ? minSum(grid, dp, i + 1, j) : INT_MAX;

        int right = (j + 1 < m) ? minSum(grid, dp, i, j + 1) : INT_MAX;
            
        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp1(n, vector<int>(m, -1));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[n - 1][m - 1] = grid[n - 1][m  - 1];

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1)
                    continue;
                
                int down  = (i+1 < n) ? dp[i+1][j] : INT_MAX;
                int right = (j+1 < m) ? dp[i][j+1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(down, right);
            }
        }

        return dp[0][0];
        // return minSum(grid, dp, 0, 0);
    }

};