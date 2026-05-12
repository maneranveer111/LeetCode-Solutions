class Solution {
public:
    bool helper(vector<int>& nums, vector<vector<int>>& dp, int idx, int target) {
        if(target == 0) 
            return true;
        
        if(idx >= nums.size())
            return false;
        
        if(dp[idx][target] != -1)
            return dp[idx][target];

        bool take = false;
        if(nums[idx] <= target)
            take = helper(nums, dp, idx + 1, target - nums[idx]);
        
        bool nontake = helper(nums, dp, idx + 1, target);

        if(take || nontake)
            dp[idx][target] = 1;
        else
            dp[idx][target] = 0;

        return dp[idx][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return false;
        int total = 0;
        for(int i = 0; i < n; i++)
            total += nums[i];
        
        if(total % 2 != 0)
            return false;
        
        int target = total / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(nums, dp, 0, target);
    }
};