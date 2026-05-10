class Solution {
public:
    
    int solve(int idx, vector<int>& nums, int target, vector<int>& dp) {
        int n = nums.size();
        
        if(idx == n - 1)
            return 0;

        if(dp[idx] != -2)
            return dp[idx];

        int maxi = -1;

        for(int j = idx + 1; j < n; j++) {

            if(abs(nums[idx] - nums[j]) <= target) {

                int next = solve(j, nums, target, dp);

                if(next != -1) {
                    maxi = max(maxi, 1 + next);
                }
            }
        }

        return dp[idx] = maxi;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -2);

        return solve(0, nums, target, dp);
    }
};