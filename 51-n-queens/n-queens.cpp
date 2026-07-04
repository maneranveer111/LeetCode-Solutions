class Solution {
public:
    void solver(int col, int n, vector<int>& lowerdig, vector<int>& upperdig, vector<int>& leftcol,
            vector<string>& board, vector<vector<string>>& ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(leftcol[row] == 0 && lowerdig[col + row] == 0 && upperdig[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftcol[row] = 1;
                lowerdig[col + row] = 1;
                upperdig[n - 1 + col - row] = 1;
                solver(col + 1, n, lowerdig, upperdig, leftcol, board, ans);
                board[row][col] = '.';
                leftcol[row] = 0;
                lowerdig[col + row] = 0;
                upperdig[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');

        for(int i = 0; i < n; i++) 
            board[i] = s;
        
        vector<int> leftcol(n, 0), lowerdig(2 * n - 1, 0), upperdig(2 * n - 1, 0);

        solver(0, n, lowerdig, upperdig, leftcol, board, ans);

        return ans;
        
    }
};