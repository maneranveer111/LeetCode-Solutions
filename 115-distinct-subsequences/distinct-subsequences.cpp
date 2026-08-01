class Solution {
public:
    vector<vector<int>> memo;

    int helper(string& s, string& t, int i, int j) {
        if(j == t.size())
            return 1;
        if(i == s.size())
            return 0;   

        if(memo[i][j] != -1)
            return memo[i][j];

        int moveboth = 0, move1 = 0;
        if(s[i] == t[j])
            moveboth = helper(s, t, i + 1, j + 1);
        move1 = helper(s, t, i + 1, j);

        return memo[i][j] = moveboth + move1;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        memo.assign(n, vector<int>(m, -1));

        return helper(s, t, 0, 0);
    }
};