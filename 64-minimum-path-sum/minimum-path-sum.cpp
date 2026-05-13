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
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return minSum(grid, dp, 0, 0);
    }

};