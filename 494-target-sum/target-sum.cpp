class Solution {
public:
    int ans = 0;
    void helper(vector<int>& nums, int target, int& ans, int currVal, int idx) {

        if (idx == nums.size()) {
            if (currVal == target) 
                ans++;
            return;                 
        }

        helper(nums, target, ans, currVal + nums[idx], idx + 1);

        helper(nums, target, ans, currVal - nums[idx], idx + 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums, target, ans, 0, 0);
        return ans;
    }


};
