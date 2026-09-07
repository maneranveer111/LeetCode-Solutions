class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> last(26, -1);

        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            dp[i + 1] = (2 * dp[i]) % MOD;

            if(last[c] != -1) {
                dp[i + 1] = (dp[i + 1] - dp[last[c] - 1] + MOD) % MOD;
            } 

            last[c] = i + 1;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};