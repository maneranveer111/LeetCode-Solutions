class Solution {
public:
    vector<vector<int>> dp;

    bool helper(string& s, string& p, int i, int j) {
        if(i == s.size() && j == p.size())
            return true;
        
        if(i == s.size()) {
            while(j + 1 < p.size() && p[j + 1] == '*') j += 2;
            return j == p.size();
        }
        
        if(j >= p.size())
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(j + 1 < p.size() && p[j + 1] == '*') {
            if(s[i] == p[j] || p[j] == '.') {
                if(helper(s, p, i + 1, j))
                    return dp[i][j] = true;
            }
            return dp[i][j] = helper(s, p, i, j + 2);
        }
        else {
            if(s[i] == p[j] || p[j] == '.') {
                return dp[i][j] = helper(s, p, i + 1, j + 1);
            }
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size(), vector<int>(p.size(), -1));
        return helper(s, p, 0, 0);
    }
};