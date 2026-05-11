class Solution {
public:

    int helper(vector<int>& nums, int idx, int prevIdx,
               vector<vector<int>>& dp) {

        if(idx == nums.size())
            return 0;

        if(dp[idx][prevIdx + 1] != -1)
            return dp[idx][prevIdx + 1];

        // not take
        int nonTake = helper(nums, idx + 1, prevIdx, dp);

        // take
        int take = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            take = 1 + helper(nums, idx + 1, idx, dp);
        }

        return dp[idx][prevIdx + 1] = max(take, nonTake);
    }

    int lengthOfLIS(vector<int>& nums) {

        // int n = nums.size();

        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // return helper(nums, 0, -1, dp);
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // idx goes from n-1 to 0
        for(int idx = n - 1; idx >= 0; idx--) {

            // prevIdx goes from idx-1 to -1
            for(int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {

                int nonTake = dp[idx + 1][prevIdx + 1];

                int take = 0;

                if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    take = 1 + dp[idx + 1][idx + 1];
                }

                dp[idx][prevIdx + 1] = max(take, nonTake);
            }
        }

        return dp[0][0];
    }
};