class Solution {
public:
    int n;
    vector<long long> dp;

    long long helper(int i, vector<vector<int>>& questions) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long take = questions[i][0] + helper(i + questions[i][1] + 1, questions);
        long long skip = helper(i + 1, questions);

        return dp[i] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        dp.assign(n, -1);
        return helper(0, questions);
    }
};