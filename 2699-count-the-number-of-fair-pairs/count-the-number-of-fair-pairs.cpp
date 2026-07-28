class Solution {
public:
    long long helper(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        long long cnt = 0;

        while(lo < hi) {
            if(nums[lo] + nums[hi] <= target) {
                cnt += hi - lo;
                lo++;
            }
            else
                hi--;
        }

        return cnt;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return helper(nums, upper) - helper(nums, lower - 1);
    }
};