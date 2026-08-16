class Solution {
public:
    vector<vector<long long>> memo;

    long long helper(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        long long ans = LLONG_MIN;

        for (int k = i; k <= j; k++) {
            long long curr = (long long)nums[i - 1] * nums[j + 1] * nums[k];
            curr += helper(i, k - 1, nums) + helper(k + 1, j, nums);
            ans = max(curr, ans);
        }

        return memo[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memo.assign(n + 2, vector<long long>(n + 2, -1));
        
        vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                long long ans = LLONG_MIN;

                for (int k = i; k <= j; k++) {
                    long long curr = (long long)nums[i - 1] * nums[j + 1] * nums[k];
                    curr += dp[i][k - 1] + dp[k + 1][j];
                    ans = max(curr, ans);
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][n];
        // return (int)helper(1, n, nums);
    }
};