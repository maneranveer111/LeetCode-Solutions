class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(26, 0);
        int len = 1;

        for(int i = 0; i < s.size(); i++) {
            if(i > 0) {
                if(s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25)
                    len++;
                else 
                    len = 1;
            }

            int idx = s[i] - 'a';
            dp[idx] = max(dp[idx], len);
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) 
            ans += dp[i];

        return ans;
    }
};