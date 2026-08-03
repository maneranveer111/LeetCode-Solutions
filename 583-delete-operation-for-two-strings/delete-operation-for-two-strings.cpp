class Solution {
public:
    vector<vector<int>> memo;

    int helper(string& word1, string& word2, int i, int j) {
        if(i == word1.size() && j == word2.size())
            return 0;
        
        if(i == word1.size())
            return word2.size() - j;
        
        if(j == word2.size())
            return word1.size() - i;

        if(memo[i][j] != -1)
            return memo[i][j];

        int con = 1e7, from1 = 1e7, from2 = 1e7;
        if(word1[i] == word2[j])
            con = helper(word1, word2, i + 1, j + 1);
        else {
            from1 = 1 + helper(word1, word2, i + 1, j);
            from2 = 1 + helper(word1, word2, i, j + 1);
        }

        return memo[i][j] = min(con, min(from1, from2));
    }

    int minDistance(string word1, string word2) {
        memo.assign(word1.size(), vector<int>(word2.size(), -1));
        
        return helper(word1, word2, 0, 0);   
    }
};