class Solution {
public:
    vector<int> dp;
    bool helper(string& s, int minJump, int maxJump, int idx) {
        if(idx == s.size() - 1) 
            return true;

        if(dp[idx] != -1)
            return dp[idx];
        
        for(int i = idx + minJump; i < s.size(); i++) {
            bool ans = false;
            if(i <= min((idx + maxJump), ((int)s.size() - 1)) && s[i] == '0')
                ans = helper(s, minJump, maxJump, i);
            if(ans)
                return true; 
        }   

        return dp[idx] = false;
    }

    bool canReach(string s, int minJump, int maxJump) {
        // dp.assign(s.size(), -1);
        // return helper(s, minJump, maxJump, 0);
        int n = s.size();
        if(s[n - 1] != '0')
            return false;
        
        vector<int> prefix(n + 1, 0);
        prefix[1] = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == '1') {
                prefix[i + 1] = prefix[i];
                continue;
            }

            int lft = max(0, i - maxJump);
            int rht = i - minJump;

            if(rht < 0) {
                prefix[i + 1] = prefix[i];
                continue;
            }

            int cnt = prefix[rht + 1] - prefix[lft];
            if(cnt > 0) {
                prefix[i + 1] = prefix[i] + 1;
            }
            else {
                prefix[i + 1] = prefix[i];
            }
        }


        return prefix[n] > prefix[n - 1];
    }
};