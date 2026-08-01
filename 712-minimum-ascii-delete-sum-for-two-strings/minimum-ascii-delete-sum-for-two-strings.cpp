class Solution {
public:
    vector<vector<int>> memo;

    int helper(string& s1, string& s2, int i, int j) {        
        if(i == s1.size()) {
            int sum = 0;
            for(int k = j; k < s2.size(); k++)
                sum += s2[k];
            return sum;
        }

        if(j == s2.size()) {
            int sum = 0;
            for(int k = i; k < s1.size(); k++)
                sum += s1[k];
            return sum;
        }
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int res = INT_MAX, from1 = INT_MAX, from2 = INT_MAX;

        if(s1[i] == s2[j])
            res = helper(s1, s2, i + 1, j + 1);
        else {

            from1 = (int)s1[i] + helper(s1, s2, i + 1, j);
            from2 = (int)s2[j] + helper(s1, s2, i, j + 1);
        }

        return memo[i][j] = min(res, min(from1, from2));
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        memo.assign(n, vector<int>(m, -1));

        return helper(s1, s2, 0, 0);
    }
};