class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>> memo;

    int helper(int idx, int n, int currProfit, int minProfit, vector<int>& group, vector<int>& profit) {
        if (idx == group.size())
            return currProfit >= minProfit ? 1 : 0;

        if (memo[idx][n][currProfit] != -1)
            return memo[idx][n][currProfit];

        int skip = helper(idx + 1, n, currProfit, minProfit, group, profit);

        int take = 0;
        if (n >= group[idx])
            take = helper(idx + 1, n - group[idx],
                          min(minProfit, currProfit + profit[idx]),
                          minProfit, group, profit);

        return memo[idx][n][currProfit] = (take + skip) % mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memo.assign(group.size(),
                    vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return helper(0, n, 0, minProfit, group, profit);
    }
};