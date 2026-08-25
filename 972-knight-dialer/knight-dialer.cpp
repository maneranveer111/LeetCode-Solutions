class Solution {
public:
    const int MOD = 1e9 + 7;
    int di[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dj[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    int memo[4][3][5001];
    bool visited[4][3][5001];

    bool isValid(int i, int j) {
        if(i < 0 || j < 0 || i >= 4 || j >= 3) return false;
        if(i == 3 && (j == 0 || j == 2)) return false; 
        return true;
    }

    int helper(int i, int j, int remaining) {
        if(remaining == 0)
            return 1;

        if(visited[i][j][remaining])
            return memo[i][j][remaining];

        visited[i][j][remaining] = true;

        long long count = 0;
        for(int d = 0; d < 8; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if(isValid(ni, nj))
                count = (count + helper(ni, nj, remaining - 1)) % MOD;
        }

        return memo[i][j][remaining] = (int)count;
    }

    int knightDialer(int n) {
        memset(visited, false, sizeof(visited));

        long long ans = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == 3 && (j == 0 || j == 2))
                    continue;

                ans = (ans + helper(i, j, n - 1)) % MOD;
            }
        }

        return (int)ans;
    }
};