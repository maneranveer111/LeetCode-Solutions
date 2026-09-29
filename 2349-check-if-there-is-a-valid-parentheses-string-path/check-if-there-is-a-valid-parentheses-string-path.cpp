class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> memo;

    bool helper(int i, int j, int cnt, vector<vector<char>>& grid) {
        if(i >= m || i < 0 || j < 0 || j >= n || cnt < 0)
            return false;

        if(grid[i][j] == '(')
            cnt++;
        else
            cnt--;

        if(cnt < 0)
            return false;

        if(i == m - 1 && j == n - 1)
            return cnt == 0;

        if(memo[i][j][cnt] != -1)
            return memo[i][j][cnt];

        bool dwn = false, rht = false;

        dwn = helper(i + 1, j, cnt, grid);
        if(dwn)
            return memo[i][j][cnt] = true;
        rht = helper(i, j + 1, cnt, grid);

        return memo[i][j][cnt] = rht;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if((m + n - 1) % 2 == 1)
            return false;
        memo.assign(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        return helper(0, 0, 0, grid);
    }
};