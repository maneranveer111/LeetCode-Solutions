class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n), col(n);
        vector<vector<int>> store(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            int maxr= INT_MIN;
            for(int j = 0; j < n; j++) {
                maxr = max(maxr, grid[i][j]);
            }
            int maxv = INT_MIN;
            for(int j = 0; j < n; j++) {
                maxv = max(maxv, grid[j][i]);
            }

            row[i] = maxr;
            col[i] = maxv;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += abs(grid[i][j] - min(row[i], col[j]));
            }
        } 


        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         ans += abs(grid[i][j] - store[i][j]);
        //     }
        // }        

        return ans;
    }
};