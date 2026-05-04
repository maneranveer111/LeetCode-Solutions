class Solution {
public:

    // int helper(int n, vector<int>& dp){
    //     if(n == 0 || n == 1) return n;
    //     if(dp[n] != -1) return dp[n];

    //     return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    // }

    int fib(int n) {
        if(n <= 1)
            return n;
        int prev1 = 1, prev2 = 0;
        int curr = 0;

        for(int i = 2; i <= n; i++) {
            // int temp = curr;
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};