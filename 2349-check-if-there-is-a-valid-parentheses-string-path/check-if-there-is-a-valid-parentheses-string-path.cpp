class Solution {
public:
    int m, n;
    vector<vector<vector<char>>> memo;  

    bool helper(int i, int j, int cnt, vector<vector<char>>& grid) {
        if (i >= m || j >= n)
            return false;

        cnt += (grid[i][j] == '(') ? 1 : -1;

        if (cnt < 0)                       
            return false;

        if (i == m - 1 && j == n - 1)
            return cnt == 0;

        if (memo[i][j][cnt])
            return false;
        memo[i][j][cnt] = 1;

        return helper(i + 1, j, cnt, grid) || helper(i, j + 1, cnt, grid);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 == 1)
            return false;

        memo.assign(m, vector<vector<char>>(n, vector<char>(m + n, 0)));

        return helper(0, 0, 0, grid);
    }
};