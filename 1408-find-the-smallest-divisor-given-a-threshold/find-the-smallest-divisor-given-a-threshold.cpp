class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = INT_MAX;
        int maxi = *max_element(nums.begin(), nums.end());
        hi = maxi;  

        int ans = lo;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int result = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] % mid == 0)
                    result += nums[i] / mid;
                else 
                    result += (nums[i] / mid) + 1;
            }

            if(result > threshold) 
                lo = mid + 1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }

        return ans;
    }   
};