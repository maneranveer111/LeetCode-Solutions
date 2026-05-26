class Solution {
public:
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    // const int MOD = 1e7;
    vector<vector<vector<long double>>> dp;

    long double helper(int n, int k, int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= n)
            return 0;
        
        if(k == 0 && i >= 0 && i < n && j >= 0 && j < n)    
            return 1;

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        long double ans = 0;

        for(int l = 0; l < 8; l++) {
            int nr = i + dx[l];
            int nc = j + dy[l];

            long double next = helper(n, k - 1, nr, nc);
            ans += next;
        }

        return dp[i][j][k] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        dp.assign(n, vector<vector<long double>>(n, vector<long double>(k + 1, -1)));

        long double cnt = helper(n, k, row, column);
        long double btm = pow(8, k);
        long double probab = (double)cnt / btm;

        return probab;
    }
};

