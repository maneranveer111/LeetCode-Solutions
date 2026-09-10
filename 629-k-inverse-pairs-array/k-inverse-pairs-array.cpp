class Solution {
public:
    int memo[1001][1001];
    const int MOD = 1e9 + 7;

    int helper(int n, int k) {
        if(n == 0)
            return 0;
        if(k == 0)
            return 1;
            
        if(memo[n][k] != -1)
            return memo[n][k];

        int ans = 0;

        for(int i = 0; i <= min(n - 1, k); i++) {
            ans = (ans % MOD + helper(n - 1, k - i) % MOD) % MOD;           
        }

        return memo[n][k] = ans;
    }

    int kInversePairs(int n, int k) {
        memset(memo, -1, sizeof(memo));
        // return helper(n, k);
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= k; j++) {

        //         for(int inv = 0; inv <= min(i - 1, j); inv++) {
        //             dp[i][j] = (dp[i][j] % MOD +  dp[i - 1][j - inv] % MOD) % MOD;
        //         }

        //     }
        // }


        for(int i = 1; i <= n; i++) {
            long long prevsum = 1;
            
            for(int j = 1; j <= k; j++) {
                prevsum += dp[i - 1][j] % MOD;

                if(j - i >= 0) 
                    prevsum -= dp[i - 1][j - i];
                
                dp[i][j] = prevsum % MOD;
            }
        }

        return dp[n][k];
    }
};