class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int ans = 1;

        for(int x : arr) {
            dp[x] = 1 + (dp.count(x - difference) ? dp[x - difference] : 0);
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};