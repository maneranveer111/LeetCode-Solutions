class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int m, n;
    // vector<vector<int>> vis;
    vector<vector<int>> memo;

    int helper(int i, int j, vector<vector<int>>& matrix) {
        // if(vis[i][j] != -1) 
        //     return 0;
        int ans = 0;
        // vis[i][j] = 1;
        if(memo[i][j] != -1)
            return memo[i][j];

        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                int tmp = 1 + helper(ni, nj, matrix);
                ans = max(ans, tmp);
            }
        }

        // vis[i][j] = -1;

        return memo[i][j] = ans;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        // vis.assign(m, vector<int>(n, -1));
        memo.assign(m, vector<int>(n, -1));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                    int tmp = helper(i, j, matrix);
                    ans = max(tmp, ans);
            }
        }

        return ans + 1;
    }
};