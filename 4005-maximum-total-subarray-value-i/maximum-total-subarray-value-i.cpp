class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();

        long long maxi = *max_element(nums.begin(), nums.end());
        long long mini = *min_element(nums.begin(), nums.end());

        ans = k * 1LL * (maxi - mini);

        return ans;
    }
};