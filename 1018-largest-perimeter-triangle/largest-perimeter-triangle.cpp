class Solution {
public:
    bool isValid(int a, int b, int c) {
        return a + b > c && b + c > a && c + a > b;
    }
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxPerimeter = 0;
        for(int i = 2; i < n; i++) {
            if(isValid(nums[i], nums[i - 1], nums[i - 2])) {
                maxPerimeter = max(maxPerimeter, nums[i] + nums[i - 1] + nums[i - 2]);
            }
        }

        return maxPerimeter;
    }
};