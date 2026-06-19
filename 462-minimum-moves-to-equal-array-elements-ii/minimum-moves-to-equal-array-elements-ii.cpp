class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans;
        if(n%2 == 0) {
            int mid = n/2;
            ans = (nums[mid] + nums[mid-1])/2;
        } else {
            ans =  nums[n/2];
        }

        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += abs(ans - nums[i]);
        }
        return sum;
    }
};