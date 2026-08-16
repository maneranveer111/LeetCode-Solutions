class Solution {
public:
    vector<vector<int>> memo;

    int helper(int i, int j, vector<int>& cuts) {
        if(i > j)
            return 0;
    
        if(memo[i][j] != -1)
            return memo[i][j];

        int ans = INT_MAX;

        for(int k = i; k <= j; k++) {
            int curr = cuts[j + 1] - cuts[i - 1];
            curr += helper(i, k - 1, cuts) + helper(k + 1, j, cuts);

            ans = min(curr, ans);
        }

        return memo[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<int> newCuts(m + 2);
        newCuts[0] = 0, newCuts[m + 1] = n;
        int i = 1;
        for(int j = 0; j < m; j++)
            newCuts[i++] = cuts[j];

        memo.assign(m + 2, vector<int>(m + 2, -1));

        return helper(1, m, newCuts);
    }
};