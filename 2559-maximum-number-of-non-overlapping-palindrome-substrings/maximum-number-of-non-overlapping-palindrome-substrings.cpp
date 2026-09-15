class Solution {
public:
    vector<int> memo;

    bool isPalindrome(int lft, int rht, string s) {
        while(lft < rht) {
            if(s[lft] != s[rht])
                return false;
            lft++;
            rht--;
        }

        return true;
    }

    int helper(int i, int k, string& s) {
        int n = s.size();

        if(i >= n)
            return 0;

        if(memo[i] != -1)
            return memo[i];
        
        int skip = helper(i + 1, k, s);

        int take = 0;
        for(int j = k; j <= k + 1; j++) {
            if(i + j <= n && isPalindrome(i, i + j - 1, s))
                take = max(take, 1 + helper(i + j, k, s));
        }

        return memo[i] = max(skip, take);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        memo.assign(n + 1, -1);

        return helper(0, k, s);
    }
};