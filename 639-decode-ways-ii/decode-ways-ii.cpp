class Solution {
public:
    int twoCharWays(char right) {
        int d = right - '0';
        if (d <= 6) return 2;   
        else        return 1;   
    }

    const int MOD = 1e9 + 7;

    int helper(string& s, int idx, vector<int>& memo) {
        if(idx >= s.size())
            return 1;
         
        if(memo[idx] != -1)
            return memo[idx];

        if(s[idx] == '*') {
            int sStr = 0, strDig = 0, digStr = 0, strStr = 0;

            sStr = 9LL * helper(s, idx + 1, memo) % MOD; 

            if(idx != s.size() - 1) {
                if(s[idx + 1] != '*') {
                    int mul = twoCharWays(s[idx + 1]);

                    strDig = mul * helper(s, idx + 2, memo) % MOD;
                }
                else {
                    strStr = 15LL * helper(s, idx + 2, memo) % MOD;
                }
            }

            return memo[idx] = (sStr +  strDig + strStr) % MOD;
        }
        else {
            if(s[idx] == '0')
            return memo[idx] = 0;

            int single = 0;
            if(s[idx] >= '1' && s[idx] <= '9')
                single = helper(s, idx + 1, memo) % MOD;
            
            int two = 0;
            if (idx != s.size() - 1 && s[idx] != '*') {
                if (s[idx + 1] == '*') {
                    if (s[idx] == '1')      
                        two = 9LL * helper(s, idx + 2, memo) % MOD;
                    else if (s[idx] == '2') 
                        two = 6LL * helper(s, idx + 2, memo) % MOD;
                } 
                else if (stoi(s.substr(idx, 2)) <= 26) {
                    two = helper(s, idx + 2, memo) % MOD;
                }
            }

            return memo[idx] = (single + two) % MOD;
        }

        return memo[idx] = 0;
    }

    int numDecodings(string s) {
        // vector<int> memo(s.size(), -1);
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1;

        for(int idx = s.size() - 1; idx >= 0; idx--) {
            if(s[idx] == '*') {
                int sStr = 0, strDig = 0, digStr = 0, strStr = 0;

                sStr = 9LL * dp[idx + 1] % MOD; 

                if(idx != s.size() - 1) {
                    if(s[idx + 1] != '*') {
                        int mul = twoCharWays(s[idx + 1]);

                        strDig = mul * dp[idx + 2] % MOD;
                    }
                    else {
                        strStr = 15LL * dp[idx + 2] % MOD;
                    }
                }

                dp[idx] = (sStr +  strDig + strStr) % MOD;
            }
            else {
                if(s[idx] == '0'){
                    dp[idx] = 0;
                    continue;
                }

                int single = 0;
                if(s[idx] >= '1' && s[idx] <= '9')
                    single = dp[idx + 1] % MOD;
                
                int two = 0;
                if (idx != s.size() - 1 && s[idx] != '*') {
                    if (s[idx + 1] == '*') {
                        if (s[idx] == '1')      
                            two = 9LL * dp[idx + 2] % MOD;
                        else if (s[idx] == '2') 
                            two = 6LL * dp[idx + 2] % MOD;
                    } 
                    else if (stoi(s.substr(idx, 2)) <= 26) {
                        two = dp[idx + 2] % MOD;
                    }
                }

                dp[idx] = (single + two) % MOD;
            }
        }

        return dp[0];
    }
};

