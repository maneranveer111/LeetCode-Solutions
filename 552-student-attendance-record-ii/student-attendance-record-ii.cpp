class Solution {
public:
    int n;
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>> memo;

    int helper(int idx, int abs, int last) {
        if (abs >= 2 || last >= 3)
            return 0;
        if (idx == n)
            return 1;

        if (memo[idx][abs][last] != -1)
            return memo[idx][abs][last];

        long long total = 0;
        total += helper(idx + 1, abs + 1, 0);   
        total += helper(idx + 1, abs, 0);       
        total += helper(idx + 1, abs, last + 1);

        return memo[idx][abs][last] = total % mod;
    }

    int checkRecord(int t) {
        n = t;
        memo.assign(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 0, 0);
    }
};