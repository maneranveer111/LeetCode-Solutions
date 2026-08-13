class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        vector<vector<int>> liveCount(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int d = 0; d < 8; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 1) {
                        count++;
                    }
                }
                liveCount[i][j] = count;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {

                    if (liveCount[i][j] < 2 || liveCount[i][j] > 3)
                        board[i][j] = 0;
                } else {

                    if (liveCount[i][j] == 3)
                        board[i][j] = 1; 
                }
            }
        }
    }
};