class Solution {
public:
    vector<vector<int>> cost;
    vector<vector<int>> memo;

    void findChangeChar(string& s) {
        int n = s.size();
        cost.assign(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j] ? 1 : 0);
            }
        }
    }

    int helper(int idx, int curr_k, int k, string& s) {
        if (idx == s.size())
            return (curr_k == k) ? 0 : 1e6;

        if(curr_k > k)
            return 1e6;
        if(memo[idx][curr_k] != -1)
            return memo[idx][curr_k];

        int ans = INT_MAX;

        for(int i = idx; i < s.size(); i++) {
            int changeChar = cost[idx][i];
            int curr = changeChar + helper(i + 1, curr_k + 1, k, s);
            ans = min(curr, ans);
        }

        return memo[idx][curr_k] = ans;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));

        findChangeChar(s);

        return helper(0, 0, k, s);
    }
};