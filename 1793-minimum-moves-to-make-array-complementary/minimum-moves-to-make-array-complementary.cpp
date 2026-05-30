class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        // diff array over target sums [2, 2*limit]
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);
            // a <= b guaranteed

            // Baseline: 2 moves for entire range [2, 2*limit]
            diff[2]             += 2;
            diff[2 * limit + 1] -= 2;

            // 1-move range: [1+a, b+limit]
            // - Replace a (keep b): target in [1+b, b+limit]
            // - Replace b (keep a): target in [1+a, a+limit]
            // Union = [1+a, b+limit]  (since a <= b)
            diff[1 + a]         -= 1;
            diff[b + limit + 1] += 1;

            // 0-move point: exactly a+b (already correct, no change needed)
            diff[a + b]     -= 1;
            diff[a + b + 1] += 1;
        }

        // Sweep prefix sum, find minimum
        int ans = INT_MAX, curr = 0;
        for (int t = 2; t <= 2 * limit; t++) {
            curr += diff[t];
            ans = min(ans, curr);
        }

        return ans;
    }
};
