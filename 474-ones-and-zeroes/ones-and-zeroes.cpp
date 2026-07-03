class Solution {
public:
    vector<vector<vector<int>>> memo;
    int helper(int idx, vector<string>& strs, vector<pair<int, int>>& cnt, int m, int n) {
        if(m < 0 || n < 0)
            return 0;
        if(idx >= strs.size())
            return 0;
        if(memo[idx][m][n] != -1)
            return memo[idx][m][n];

        int take = 0, nontake = 0;
        if(cnt[idx].first <= n && cnt[idx].second <= m)
            take = 1 + helper(idx + 1, strs, cnt, m - cnt[idx].second, n - cnt[idx].first);
        
        nontake = helper(idx + 1, strs, cnt, m, n);

        return memo[idx][m][n] = max(take, nontake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memo.assign(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        vector<pair<int, int>> cnt(strs.size());
        int i = 0;
        for(string& s : strs) {
            int one = 0, zero = 0;
            for(char ch : s) {
                if(ch == '1')
                    one++;
                else
                    zero++;
            }
            
            cnt[i] = {one, zero};
            i++;
        }

        return helper(0, strs, cnt, m, n);
    } 
};