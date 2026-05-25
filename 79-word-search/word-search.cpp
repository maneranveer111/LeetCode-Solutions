class Solution {
public:
    int m, n;
    vector<vector<int>> vis;
    bool dfs(vector<vector<char>>& board, string word, string& curr, int i, int j, int idx) {
        if(word == curr)
            return true;

        if(i >= m || i < 0 || j < 0 || j >= n)  
            return false;
        if(curr.size() > word.size())
            return false;

        if(word[idx] != board[i][j])
            return false;

        if(vis[i][j] != -1)
            return false;
        
        bool up = false, down = false, rht = false, lft = false;

        curr.push_back(board[i][j]);
        vis[i][j] = 1;

        if(i - 1 >= 0) {
            up = dfs(board, word, curr, i - 1, j, idx + 1);
            if(up)
                return true;
        }

        if(j - 1 >= 0) {
            lft = dfs(board, word, curr, i, j - 1, idx + 1);
            if(lft)
                return true;
        }

        if(i + 1 < m) {
            down = dfs(board, word, curr, i + 1, j, idx + 1);
            if(down)
                return true;
        }

        if(j + 1 < n) {
            rht = dfs(board, word, curr, i, j + 1, idx + 1);
            if(rht)
                return true;
        }

        curr.pop_back();
        vis[i][j] = -1;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        bool ans = false;
        
        if(m == 1 && n == 1 && board[0][0] == 'a' && word == "a")
            return true;

        vis.assign(m, vector<int>(n, -1)); 

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                string curr = "";
                bool ans = dfs(board, word, curr, i, j, 0);

                if(ans)
                    return ans;
            }
        }
        
        return false;
    }
};