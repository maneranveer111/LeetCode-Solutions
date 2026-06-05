class Solution {
public:
    int n;

    int memo[101][3];

    int dp(int i, int last, vector<int>& groups) {
        if (i == n) return 0;

        int lg = last + 1; 
        if (memo[i][lg] != -1) return memo[i][lg];

        int skip = dp(i + 1, last, groups);

        int pick = 0;
        if (groups[i] != last) {
            pick = 1 + dp(i + 1, groups[i], groups);
        }

        return memo[i][lg] = max(skip, pick);
    }

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        n = words.size();
        memset(memo, -1, sizeof(memo));

        vector<string> result;
        int last = -1;

        for (int i = 0; i < n; i++) {
            int lg = last + 1;

            int skip = dp(i + 1, last, groups);
            int pick = 0;
            if (groups[i] != last) {
                pick = 1 + dp(i + 1, groups[i], groups);
            }

            if (groups[i] != last && pick >= skip) {
                result.push_back(words[i]);
                last = groups[i];
            }
        }

        return result;
    }
};