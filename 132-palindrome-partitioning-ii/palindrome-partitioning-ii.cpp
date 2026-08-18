class Solution {
public:
    vector<int> memo;

    bool isPalindrome(string& s, int srt, int en) {
        while(srt <= en) {
            if(s[srt] != s[en])
                return false;
            srt++;
            en--;
        }

        return true;
    }

    int helper(int idx, string& s) {
        if(idx == s.size())
            return 0;
        if(memo[idx] != -1)
            return memo[idx];

        int ans = INT_MAX;
        
        for(int i = idx; i < s.size(); i++) {
            if(isPalindrome(s, idx, i)) {
                int curr = 1 + helper(i + 1, s);
                ans = min(ans, curr);
            }
        }

        return memo[idx] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        memo.assign(n, -1);

        return helper(0, s) - 1;   
    }
};