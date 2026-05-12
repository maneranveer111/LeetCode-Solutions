class Solution {
public:
    int helper(vector<int>& coins, vector<vector<int>>& dp, int amount, int idx) {
        if(amount == 0)
            return 1;       
        if(idx == -1)
            return 0;       

        if(dp[idx][amount] != -1)
            return dp[idx][amount];


        int maxCoins = amount / coins[idx];
        int take = 0;
        for(int i = 1; i <= maxCoins; i++) {
            int temp = helper(coins, dp, amount - (i * coins[idx]), idx - 1);
            take += temp;
        }

        int nontake = helper(coins, dp, amount, idx - 1);

        return dp[idx][amount] = take + nontake;
    }

    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for(int coin : coins) {
            for(int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
                if(dp[i] > INT_MAX)       // cap to prevent overflow
                    dp[i] = INT_MAX;
            }
        }

        return (int)dp[amount];
    }
};