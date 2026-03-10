class Solution {
public:
    vector<vector<int>> memo = vector<vector<int>>(21, vector<int>(21, -1));

    int solve(vector<int>& nums, int left , int right) {
        if(left == right) return nums[left];
        if(memo[left][right] != -1) return memo[left][right];

        int peekLeft = nums[left] - solve(nums, left + 1, right);
        int peekRight = nums[right] - solve(nums, left, right - 1);

        return memo[left][right] = max(peekLeft, peekRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};