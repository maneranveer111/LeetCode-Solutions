class Solution {
public:
    int n;
    int dr[2] = {1, 0};

    int helper(int t, int i1, int i2, vector<vector<int>>& grid,
               vector<vector<vector<int>>>& dp) {

        int j1 = t - i1, j2 = t - i2;

        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || j1 < 0 || j2 < 0)
            return INT_MIN;
        
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return INT_MIN;
        
        if(dp[t][i1][i2] != -1)
            return dp[t][i1][i2];

        if(i1 == n - 1 && j1 == n - 1)
            return dp[t][i1][i2] = grid[i1][j1];
        
        int cherries = (i1 == i2) ? grid[i1][j1] :
                                    grid[i1][j1] + grid[i2][j2];
        
        int best = INT_MIN;
        for(int k = 0; k < 2; k++) {
            for(int l = 0; l < 2; l++) {
                int next = helper(t + 1, i1 + dr[k], i2 + dr[l], grid,dp);

                if(next != INT_MIN)
                    best = max(best, next);
            }
        }

        if(best == INT_MIN)
            return dp[t][i1][i2] = INT_MIN;
        
        return dp[t][i1][i2] = cherries + best;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        // t ranges 0 to 2*(n-1), i1 and i2 range 0 to n-1
        vector<vector<vector<int>>> dp(
            2 * n, vector<vector<int>>(n, vector<int>(n, -1)));

        int result = helper(0, 0, 0, grid, dp);
        return max(0, result);
    }
};