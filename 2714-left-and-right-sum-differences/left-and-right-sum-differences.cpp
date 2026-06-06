class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> pre(nums.size(), 0);
        vector<int> suf(nums.size(), 0);
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            pre[i] = sum;
            sum += nums[i];
        }

        sum = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--) {
            suf[i] = sum;
            sum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++) {
            pre[i] = abs(pre[i] - suf[i]);
        }

        return pre;
    }
};