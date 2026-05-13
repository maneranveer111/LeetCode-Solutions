class Solution {
public: 
    int n, m;
    int helper(vector<vector<int>>& dp, int i, int j) {
        if(i == n - 1 && j == m - 1)
            return 1;
        if(i > n || j > m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = (i + 1 < n) ? helper(dp, i + 1, j) : 0;
        int right = (j + 1 < m) ? helper(dp, i, j + 1) : 0;

        return dp[i][j] = right + down;
    }

    int uniquePaths(int p, int q) {
        // vector<vector<int>> visited(n)
        n = p;
        m = q;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return helper(dp, 0, 0);
    }
};