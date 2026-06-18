class Solution {
public:
    int helper(vector<int>& nums, int sum) {
        int stu = 1, currSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(currSum + nums[i] <= sum) 
                currSum += nums[i];
            else {
                currSum = nums[i];
                stu++;
            }
        }

        return stu;
    }

    int splitArray(vector<int>& nums, int k) {
        if(nums.size() < k)
            return -1;
        
        int lo = INT_MIN, hi = 0;
        for(int i = 0; i < nums.size(); i++) {
            lo = max(lo, nums[i]);
            hi += nums[i];
        }
        
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(helper(nums, mid) > k) {
                lo = mid + 1;
            }
            else 
                hi = mid - 1;
        }

        return lo;
    }
};