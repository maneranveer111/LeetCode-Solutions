class Solution {
public:
    vector<vector<int>> memo;

    int helper(string& text1, string& text2, int i, int j) {
        if(i == text1.size() || j == text2.size())
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int res = 0;    
        if(text1[i] == text2[j])
            res = 1 + helper(text1, text2, i + 1, j + 1);
        else
            res = max(helper(text1, text2, i + 1, j), helper(text1, text2, i, j + 1));

        return memo[i][j] = res;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // memo.assign(m + 1, vector<int>(n + 1, -1));
        // return helper(text1, text2, 0, 0);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[m][n];
    }
};