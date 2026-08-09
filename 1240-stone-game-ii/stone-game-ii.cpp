class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> memo;

    int helper(int idx, int m) {
        if(idx >= n)
            return 0;

        if(memo[idx][m] != -1)
            return memo[idx][m];
        
        int maxi = INT_MIN;
        for(int i = 1; i <= 2 *m && idx + i <= n; i++) {
            int nm = max(m, i);
            int take = suffix[idx] - suffix[idx + i] - helper(idx + i, nm);
            maxi = max(maxi, take);
        }

        return memo[idx][m] = maxi;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.assign(n + 1, 0);
        memo.assign(n + 1, vector<int>(n + 1, -1));
        
        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        
        int diff = helper(0, 1);
        return (suffix[0] + diff) / 2;
    }
};