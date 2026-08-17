class Solution {
public:
    vector<vector<int>> memo;
    vector<int> preSum;

    int helper(int i, int j) {
        if(i >= j)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        int ans = 0;

        for(int k = i; k < j; k++) {
            int left = preSum[k] - preSum[i - 1];
            int rht = preSum[j] - preSum[k];

            if(left > rht)
                ans = max(ans, rht + helper(k + 1, j));
            else if(rht > left)
                ans = max(ans, left + helper(i, k));
            else {
                ans = max(ans, left + max(helper(i, k), helper(k + 1, j)));
            }    
        }

        return memo[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(n == 1)
            return 0;
        
        memo.assign(n + 1, vector<int>(n + 1, -1));
        preSum.assign(n + 1, 0);
        int sum = 0;

        for(int i = 1; i <= n; i++) {
            sum += stoneValue[i - 1];
            preSum[i] = sum;
        }

        return helper(1, n);
    }
};