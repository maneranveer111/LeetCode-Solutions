class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat[0].size();   
        int n = mat.size();

        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        vector<vector<int>> ans(n, vector<int>(m, -1));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis = q.front().second; 
            ans[i][j] = dis;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push({{nx, ny}, dis + 1});
                    // ans[nx][ny] = dis + 1;
                } 
            } 
        }


        return ans;
    }
};