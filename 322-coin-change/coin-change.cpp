class Solution {
public:
    int helper(vector<int>& coins, vector<vector<int>>& dp, int amount, int idx) {
        if(idx == -1 && amount > 0)
            return INT_MAX;

        if(amount == 0)
            return 0;
        if(dp[idx][amount] != -1)
            return dp[idx][amount];

        int maxCoin = (amount / coins[idx]) + 1;
        int take = INT_MAX;
        for(int i = 1; i < maxCoin; i++) {
            int temp = helper(coins, dp, amount - (i * coins[idx]), idx - 1);
            if(temp != INT_MAX)
                temp += i;
            take = min(take, temp);
        }        

        int nontake = helper(coins, dp, amount, idx - 1);

        return dp[idx][amount] = min(take, nontake);
    }

    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
    //     int ans = helper(coins, dp, amount, n - 1);
    //     return (ans == INT_MAX) ? -1 : ans;
    // }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(coin <= i && dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }

};