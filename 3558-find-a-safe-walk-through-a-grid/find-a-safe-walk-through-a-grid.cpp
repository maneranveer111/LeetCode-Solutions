class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        dist[0][0] = grid[0][0];

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while(!dq.empty()) {
            auto node = dq.front();
            int x = node.first;
            int y = node.second;
            dq.pop_front();

            for(int i = 0; i < 4; i++) {
                int ni = x + dx[i];
                int nj = y + dy[i];

                if(ni >= m || nj >= n || ni < 0 || nj < 0)
                    continue;
                
                int w = grid[ni][nj];
                if(dist[ni][nj] > dist[x][y] + w) {
                    dist[ni][nj] = dist[x][y] + w;
                    if(w == 0)
                        dq.push_front({ni, nj});
                    else
                        dq.push_back({ni, nj});
                }
            }
        }

        return dist[m-1][n-1] <= health - 1;
    }
};