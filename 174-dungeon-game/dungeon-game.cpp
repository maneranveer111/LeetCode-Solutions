class Solution {
public:
    int n, m;
    vector<vector<int>> memo;

    int helper(int i, int j, vector<vector<int>>& dungeon) {
        if(i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        if(memo[i][j] != -1)
            return memo[i][j];

        int rht = INT_MAX, dwn = INT_MAX; 
        if(j + 1 < n)
            rht = helper(i, j + 1, dungeon);
        if(i + 1 < m)
            dwn = helper(i + 1, j, dungeon);
        
        int minNxt = min(rht, dwn);

        return memo[i][j] = max(1, minNxt - dungeon[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();   
        n = dungeon[0].size();   
        memo.assign(m, vector<int>(n, -1));

        return helper(0, 0, dungeon);
    }
};

