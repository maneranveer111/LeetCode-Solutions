class Solution {
public:
    int helper(string& word1, string& word2, vector<vector<int>>& dp, int i, int j) {
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        if(dp[i][j] != -1)
            return dp[i][j];

        int match = 1e8, ins = 1e8, del = 1e8, rep = 1e8;

        if(word1[i] == word2[j])
            return dp[i][j] = helper(word1, word2, dp, i - 1, j - 1);
        
        ins = 1 + helper(word1, word2, dp, i, j - 1);
        del = 1 + helper(word1, word2, dp, i - 1, j);
        rep = 1 + helper(word1, word2, dp, i - 1, j - 1);

        return dp[i][j] = min(match, min(ins, min(del, rep)));
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));



        return helper(word1, word2, dp, word1.size() - 1, word2.size() - 1);
    }
};