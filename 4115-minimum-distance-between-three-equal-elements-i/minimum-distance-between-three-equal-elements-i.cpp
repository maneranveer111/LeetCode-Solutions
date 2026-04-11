class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // Group indices by value
        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        int ans = INT_MAX;

        for (auto& [key, vec] : mp) {
            // Need at least 3 indices
            if (vec.size() >= 3) {
                // Check every 3 consecutive indices
                for (int i = 0; i + 2 < (int)vec.size(); i++) {
                    int p = vec[i];
                    int q = vec[i + 1];
                    int r = vec[i + 2];

                    // distance = 2 * (r - p) since p < q < r
                    int dist = abs(p - q) + abs(q - r) + abs(r - p);
                    ans = min(ans, dist);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};