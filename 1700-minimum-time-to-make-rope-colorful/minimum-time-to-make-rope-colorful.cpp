class Solution {
public:
    vector<int> dp;
    int solve(int i, string& c, vector<int>& t, int n) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int j = i, sum = 0, mx = 0;
        while (j < n && c[j] == c[i]) {
            sum += t[j]; mx = max(mx, t[j]); j++;
        }
        return dp[i] = (sum - mx) + solve(j, c, t, n);
    }
    
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        dp.assign(n, -1);
        return solve(0, colors, neededTime, n);
    }
};