class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> windowCount; // value -> number of windows containing it

        // Slide over every window of size k
        for (int start = 0; start + k <= n; start++) {
            unordered_set<int> seenInWindow;
            for (int i = start; i < start + k; i++)
                seenInWindow.insert(nums[i]);

            // Each distinct value in this window contributes +1 to its count
            for (int val : seenInWindow)
                windowCount[val]++;
        }

        int ans = -1;
        for (auto& [val, cnt] : windowCount) {
            if (cnt == 1)
                ans = max(ans, val);
        }

        return ans;
    }
};