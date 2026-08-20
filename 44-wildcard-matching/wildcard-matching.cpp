class Solution {
public:
    vector<vector<int>> memo;

    bool helper(int i, int j, string& s, string& p) {
        if(i == s.size() && j == p.size())
            return true;
        
        if(j >= p.size())
            return false;
        
        if(i == s.size()) {
            return p[j] == '*' && helper(i, j + 1, s, p);
        }
        if(memo[i][j] != -1)
            return memo[i][j];

        bool isMatch = false, ifStar = false;

        if(s[i] == p[j] || p[j] == '?') {
            isMatch = helper(i + 1, j + 1, s, p);
            if(isMatch) 
                return memo[i][j] = true;
        }
        else if(p[j] == '*') {
            ifStar = helper(i + 1, j, s, p);
            bool skipStar = helper(i, j + 1, s, p);
            if(ifStar || skipStar)
                return memo[i][j] = true;
        }

        return memo[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        memo.assign(n, vector<int>(m, -1));
        return helper(0, 0, s, p);   
    }
};