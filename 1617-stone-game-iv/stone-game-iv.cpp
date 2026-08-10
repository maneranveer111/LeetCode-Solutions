class Solution {
public:
    vector<int> memo;

    int helper(int n) {
        if(n <= 0)
            return 0;
        if(memo[n] != -1)
            return memo[n];

        int maxi = INT_MIN;
        for(int i = 1; i * i <= n; i++) {
            int take = 1 - helper(n - (i * i));
            maxi = max(maxi, take);
        }

        return memo[n] = maxi;
    }

    bool winnerSquareGame(int n) {
        memo.assign(n + 1, -1);
        int scr = helper(n);
        if(scr > 0)
            return true;

        return false;    
    }
};