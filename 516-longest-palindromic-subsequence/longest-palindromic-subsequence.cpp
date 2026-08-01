class Solution {
public:
    vector<vector<int>> memo;

    int helper(string& s1, string& s2, int i, int j) {
        if(i == s1.size() || j == s2.size())
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int res = 0;
        if(s1[i] == s2[j])
            res = 1 + helper(s1, s2, i + 1, j + 1);
        else
            res = max(helper(s1, s2, i + 1, j), helper(s1, s2, i, j + 1));

        return memo[i][j] = res;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        memo.assign(n, vector<int>(n, -1));

        return helper(s, rev, 0, 0);
    }
};