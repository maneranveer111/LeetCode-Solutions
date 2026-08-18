class Solution {
public:
    vector<int> memo;
    vector<vector<bool>> isPalin;

    void helperPalindrome(string& s) {
        int n = s.size();
        isPalin.assign(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            isPalin[i][i] = true;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    isPalin[i][j] = (len == 2) || isPalin[i + 1][j - 1];
            }
        }
    }

    int helper(int idx, string& s) {
        if (idx == s.size())
            return 0;
        if (memo[idx] != -1)
            return memo[idx];

        int ans = INT_MAX;

        for (int i = idx; i < s.size(); i++) {
            if (isPalin[idx][i]) {                 
                int curr = 1 + helper(i + 1, s);
                ans = min(ans, curr);
            }
        }

        return memo[idx] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        memo.assign(n, -1);
        helperPalindrome(s);                

        return helper(0, s) - 1;
    }
};