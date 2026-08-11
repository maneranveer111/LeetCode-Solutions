class Solution {
public:
    int m, n;
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

    void helper(int r, int c, vector<vector<char>>& board) {
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E')
            return;

        int adjCount = findCount(r, c, board);

        if(adjCount > 0) {
            board[r][c] = '0' + adjCount;
        }
        else {
            board[r][c] = 'B';

            for(int i = 0; i < 8; i++) {
                int nr = r + dy[i];
                int nc = c + dx[i];

                if(nr < m && nc < n && nr >= 0 && nc >= 0)
                    helper(nr, nc, board);
            }
        }
    }

    int findCount(int r, int c, vector<vector<char>>& board) {
        int cnt = 0;

        for(int d = 0; d < 8; d++) {
            int nr = r + dy[d];
            int nc = c + dx[d];

            if(nr < m && nc < n && nr >= 0 && nc >= 0 && (board[nr][nc] == 'M' || board[nr][nc] == 'X'))
                cnt++;   
        }

        return cnt;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();

        int r = click[0], c = click[1];

        if(board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        helper(r, c, board);
        
        return board;
    }
};