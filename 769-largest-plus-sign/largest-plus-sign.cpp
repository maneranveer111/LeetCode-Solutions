class Solution {
public:
    int n;
    vector<vector<bool>> zeros;
    vector<vector<int>> memoL, memoR, memoU, memoD;
    
    int left(int i, int j) {
        if (j < 0 || zeros[i][j]) return 0;
        if (memoL[i][j] != -1) return memoL[i][j];
        return memoL[i][j] = 1 + left(i, j - 1);
    }
    
    int right(int i, int j) {
        if (j >= n || zeros[i][j]) return 0;
        if (memoR[i][j] != -1) return memoR[i][j];
        return memoR[i][j] = 1 + right(i, j + 1);
    }
    
    int up(int i, int j) {
        if (i < 0 || zeros[i][j]) return 0;
        if (memoU[i][j] != -1) return memoU[i][j];
        return memoU[i][j] = 1 + up(i - 1, j);
    }
    
    int down(int i, int j) {
        if (i >= n || zeros[i][j]) return 0;
        if (memoD[i][j] != -1) return memoD[i][j];
        return memoD[i][j] = 1 + down(i + 1, j);
    }
    
    int orderOfLargestPlusSign(int m, vector<vector<int>>& mines) {
        n = m;
        zeros.assign(n, vector<bool>(n, false));
        for (auto& m : mines) zeros[m[0]][m[1]] = true;
        
        memoL.assign(n, vector<int>(n, -1));
        memoR.assign(n, vector<int>(n, -1));
        memoU.assign(n, vector<int>(n, -1));
        memoD.assign(n, vector<int>(n, -1));
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (zeros[i][j]) continue;
                int order = min({left(i, j), right(i, j), up(i, j), down(i, j)});
                ans = max(ans, order);
            }
        }
        return ans;
    }
};