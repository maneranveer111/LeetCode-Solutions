class Solution {
public:

    void solver(int col, int n, vector<string>& boards, vector<int>& leftCol, 
        vector<int>&lowerDig, vector<int>& upperDig, vector<vector<string>>& ans) {
            if(col == n) {
                ans.push_back(boards);
                return;
            }

            for(int row = 0; row < n; row++) {
                if(leftCol[row] == 0 && lowerDig[col + row] == 0 &&
                    upperDig[n - 1 + col - row] == 0) {
                        boards[row][col] = 'Q';
                        leftCol[row] = 1;
                        lowerDig[col + row] = 1;
                        upperDig[n - 1 + col - row] = 1;
                        solver(col + 1, n, boards, leftCol, lowerDig, upperDig, ans);
                        boards[row][col] = '.';
                        leftCol[row] = 0;
                        lowerDig[col + row] = 0;
                        upperDig[n - 1 + col - row] = 0;
                    }
            }
        }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> boards(n);
        vector<vector<string>> ans;
        string s(n, '.');

        for(int i = 0; i < n; i++) 
            boards[i] = s;
        
        vector<int> leftCol(n, 0), lowerDig(2 * n - 1, 0), upperDig(2 * n - 1, 0);

        solver(0, n, boards, leftCol, lowerDig, upperDig, ans);

        return ans;
    }
};