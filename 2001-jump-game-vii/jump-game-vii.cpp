class Solution {
public:
    vector<int> dp;
    bool helper(string& s, int minJump, int maxJump, int idx) {
        if(idx == (int)s.size() - 1)
        return true;

        if(dp[idx] != -1)
            return dp[idx];  

        int limit = min((int)s.size() - 1, idx + maxJump);  

        for(int i = idx + minJump; i <= limit; i++) {  
            if(s[i] == '0') {
                if(helper(s, minJump, maxJump, i))
                    return dp[idx] = true;   
            }
        }

        return dp[idx] = false;
    }

    bool canReach(string s, int minJump, int maxJump) {
        // if(s[s.size() - 1] != '0') return false;  t
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