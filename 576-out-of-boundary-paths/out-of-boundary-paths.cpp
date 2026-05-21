class Solution {
public:
    int helper(vector<vector<vector<int>>>& dp, int m, int n, int maxMoves, int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0)    
            return 1;

        if(maxMoves <= 0)
            return 0;
        
        if(dp[i][j][maxMoves] != -1)
            return dp[i][j][maxMoves];
        
        int up = 0, lft = 0, rht = 0, dwn = 0;
        const int large = 1e9 + 7;

        up = helper(dp, m, n, maxMoves - 1, i - 1, j);
        dwn = helper(dp, m, n, maxMoves - 1, i + 1, j);
        lft = helper(dp, m, n, maxMoves - 1, i, j - 1);
        rht = helper(dp, m, n, maxMoves - 1, i, j + 1);

        return dp[i][j][maxMoves] = 
            ((long long)up + dwn + lft + rht) % large;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        return helper(dp, m, n, maxMove, startRow, startColumn);
    }
};