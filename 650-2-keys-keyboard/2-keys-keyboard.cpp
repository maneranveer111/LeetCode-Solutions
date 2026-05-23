class Solution {
public:
    // int helper(int n, int curr, vector<vector<vector<int>>>& dp, int cpy, int ops) {
    //     if(ops > n)
    //         return 1e7;
    //     if(curr > n)
    //         return 1e7;
    //     if(curr == n)   
    //         return 0;

    //     if(dp[curr][cpy][ops] != -1)
    //         return dp[curr][cpy][ops];

    //     int paste = 1e8, copy = 1e8;

    //     copy = 1 + helper(n, curr, dp, curr, ops + 1);
    //     if(cpy != 0) paste = 1 + helper(n, curr + cpy, dp, cpy, ops + 1);

    //     return dp[curr][cpy][ops] = min(copy, paste);
    // }

    int minSteps(int n) {
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        int steps = 0;

        for(int i = 2; i * i <= n; i++) {
            while(n % i == 0) {
                steps += i;
                n /= i;
            }
        }

        if(n > 1) steps += n;
        return steps;
    }
};