class Solution {
public:
    int helper(vector<int>& nums, vector<vector<int>>& dp, int prev, int j, int d) {
        if(j >= nums.size())    
            return 0;
            
        if(dp[j][prev + 1] != -1)        
            return dp[j][prev + 1];

        int take = 0;
        if(prev == -1) {                  
            take = 1 + helper(nums, dp, j, j + 1, d);
        }
        else {
            if(d == 1 && nums[prev] < nums[j])
                take = 1 + helper(nums, dp, j, j + 1, -1);
            else if(d == -1 && nums[prev] > nums[j]) 
                take = 1 + helper(nums, dp, j, j + 1, 1);
        }

        int nontake = helper(nums, dp, prev, j + 1, d);

        return dp[j][prev + 1] = max(take, nontake);  
    }

    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        int p = helper(nums, dp, -1, 0, 1);
        dp.assign(nums.size(), vector<int>(nums.size() + 1, -1));  
        int n = helper(nums, dp, -1, 0, -1);

        return max(p, n);
    }
};