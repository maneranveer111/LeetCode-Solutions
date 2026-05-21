class Solution {
public:
    int helper(string& s, vector<int>& dp, int idx) {
        if(idx >= s.size())
            return 1;
        if(dp[idx] != -1)
            return dp[idx];

        if(s[idx] == '0')
            return 0;
        int single = 0;
        if(s[idx] - '0' >= 1 && s[idx] - '0' <= 9)   
                single = helper(s, dp, idx + 1);
        
        int two = 0;
        if(idx != s.size() - 1)
            if(s[idx] != '0' && stoi(s.substr(idx, 2)) <= 26)
                two = helper(s, dp, idx + 2);
        
        return dp[idx] = single + two;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return helper(s, dp, 0);
    }
};