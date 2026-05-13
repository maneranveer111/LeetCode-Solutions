class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(); 
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1) 
            return 0;

        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        dp[n-1][m-1] = 1;

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(i == n-1 && j == m-1) continue;
                if(obstacleGrid[i][j] == 1) continue;
                
                long long down  = (i+1 < n) ? dp[i+1][j] : 0;
                long long right = (j+1 < m) ? dp[i][j+1] : 0;

                dp[i][j] = down + right;
            }
        }

        return (int)dp[0][0];
    }
};