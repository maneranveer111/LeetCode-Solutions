class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int helper(vector<vector<char>>& matrix, int i, int j) {
        if(i >= m || i < 0 || j >= n || j < 0)
            return 0;
    
        if(matrix[i][j] == '0')
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int lft = 0, up = 0, lftUp = 0;
        lft = helper(matrix, i, j - 1);
        up = helper(matrix, i - 1, j);
        lftUp = helper(matrix, i - 1, j - 1);

        return dp[i][j] = 1 + min(lft, min(up, lftUp));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1));
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0')
                    continue;
                int temp = helper(matrix, i, j);
                ans = max(ans, temp);
            }
        }
        return ans * ans;
    }
};