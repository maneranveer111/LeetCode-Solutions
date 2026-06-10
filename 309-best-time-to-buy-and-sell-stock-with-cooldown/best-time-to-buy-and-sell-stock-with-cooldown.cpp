class Solution {
public:
    int dp[5001][1001][2];

    int helper(vector<int>& prices, int idx, int amt, int flag) {
        if (idx >= (int)prices.size())
            return 0;

        if (dp[idx][amt][flag] != -1)
            return dp[idx][amt][flag];

        int result = 0;

        if (flag == 0) {
            int buy   = helper(prices, idx + 1, prices[idx], 1);
            int nobuy = helper(prices, idx + 1, amt, 0);
            result = max(buy, nobuy);
        } else {
            int sell   = (prices[idx] - amt) + helper(prices, idx + 2, 0, 0);
            int nosell = helper(prices, idx + 1, amt, 1);
            result = max(sell, nosell);
        }

        return dp[idx][amt][flag] = result;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, 0, 0);
    }
};