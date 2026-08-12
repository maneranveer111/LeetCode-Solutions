class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},
                                     {1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1; 
        int dist = 1;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int k = 0; k < sz; k++) {
                auto [x, y] = q.front(); q.pop();
                
                if(x == n-1 && y == n-1) return dist;
                
                for(auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != 0)
                        continue;
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            dist++;
        }
        return -1;
    }
};