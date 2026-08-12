class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    q.push({i, j});

        int dis = -1;
        if(q.empty() || q.size() == (size_t)n*n)
            return dis;

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()) {
            int sz = q.size();
            dis++;

            for(int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(auto& d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dis;
    }
};