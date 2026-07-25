class Solution {
public:
    vector<int> dp;

    int helper(int idx, vector<vector<int>>& pairs, int prev) {
        if(idx == pairs.size())
            return 0;
        
        int take = 0, nontake = 0;
        if(dp[idx] != -1)
            return dp[idx];

        if(prev < pairs[idx][0])
            take = 1 + helper(idx + 1, pairs, pairs[idx][1]);
        nontake = helper(idx + 1, pairs, prev);

        return dp[idx] = max(take, nontake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        dp.assign(pairs.size(), -1);
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int len = 0, prev = INT_MIN;

        for(auto arr : pairs) {
            if(arr[0] > prev) {
                len++;
                prev = arr[1];
            }
        }

        return helper(0, pairs, INT_MIN);
        // return len;
    }
};