class Solution {
public:
    int helper(vector<int>& nums, int diff) {
        unordered_map<int, int> dp;
        int ans = 1;

        for(int x : nums) {
            dp[x] = 1 + (dp.count(x - diff) ? dp[x - diff] : 0);
            ans = max(ans, dp[x]);
        }

        return ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());

        int maxDiff = maxEle - minEle;
        if(maxDiff == 0)
            return nums.size();
        
        int ans = 1;
        for(int d = -maxDiff; d <= maxDiff; d++) {
            int res = helper(nums, d);
            ans = max(ans, res);
        }

        return ans;
    }
};