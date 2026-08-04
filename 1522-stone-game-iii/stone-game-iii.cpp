class Solution {
public:
    vector<int> memo;
    
    int helper(int i, vector<int>& stoneValue) {
        if(i == stoneValue.size())
            return 0;
        
        if(memo[i] != INT_MIN)
            return memo[i];

        int take1 = INT_MIN, take2 = INT_MIN, take3 = INT_MIN;
        take1 = stoneValue[i] - helper(i + 1, stoneValue);
        if(i + 1 < stoneValue.size())
            take2 = stoneValue[i] + stoneValue[i + 1] - helper(i + 2, stoneValue);
        if(i + 2 < stoneValue.size())
            take3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - helper(i + 3, stoneValue);

        return memo[i] = max(take1, max(take2, take3));
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memo.assign(n + 1, INT_MIN);
        int scr = helper(0, stoneValue);
        if(scr == 0)
            return "Tie";

        return (scr > 0) ? "Alice" : "Bob";
    }
};
