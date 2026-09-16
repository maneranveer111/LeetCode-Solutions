class Solution {
public:
    int memo[1001][1001];
    const int MOD = 1e9 + 7;

    int helper(int i, int n, int k) {
        if(i >= n || k < 0)
            return 0;
        if(k == 0)
            return 1;
        if(memo[i][k] != -1)
            return memo[i][k];

        int skip = helper(i + 1, n, k);
        int ans = 0;
        for(int j = i + 1; j < n; j++) {
            ans = (ans + helper(j, n, k - 1)) % MOD;
        }
        ans = (ans + skip) % MOD;

        return memo[i][k] = ans;
    }

    int numberOfSets(int n, int k) {
        memset(memo, -1, sizeof(memo));
        // return helper(0, n, k);

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int j = 1; j <= k; j++) {
            vector<int> newDp(n + 1, 0);
            long long suffix = 0;

            for(int i = n - 1; i >= 0; i--) {
                int skip = newDp[i + 1];
                newDp[i] = (skip + suffix) % MOD;

                suffix = (suffix + dp[i][j - 1]) % MOD;
            }

            for(int i = 0; i <= n; i++)
                dp[i][j] = newDp[i];
        }

        return dp[0][k];
    }
};