class Solution {
public:
    bool helper(string& s1, string& s2, int i, int j, string& s3, vector<vector<int>>& dp) {

        if (i >= s1.size() && j >= s2.size())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool moveI = false;
        if (i < s1.size() && s1[i] == s3[i + j])
            moveI = helper(s1, s2, i + 1, j, s3, dp);

        bool moveJ = false;
        if (j < s2.size() && s2[j] == s3[i + j])
            moveJ = helper(s1, s2, i, j + 1, s3, dp);

        return dp[i][j] = moveI || moveJ;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return helper(s1, s2, 0, 0, s3, dp);
    }
};