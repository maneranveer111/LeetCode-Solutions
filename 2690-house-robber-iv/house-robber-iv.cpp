class Solution {
public:

    bool helper(int mid, vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mid) {
                cnt++;
                i++;            }
        }

        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        int ans = hi;

        while(low <= hi) {
            int mid = low + (hi - low) / 2;

            if(helper(mid, nums, k)) {
                ans = mid;
                hi = mid - 1;
            }
            else 
                low = mid + 1;
        }

        return ans;
    }
};