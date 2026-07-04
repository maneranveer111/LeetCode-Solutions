class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int r, int c, int newColor, int iniColor){
        ans[r][c] = newColor;

        for(int k = 0; k < 4; k++){
            int nr = r + dx[k];
            int nc = c + dy[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] != newColor && 
                image[nr][nc] == iniColor){
                dfs(image, ans, nr, nc, newColor, iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];

        
        dfs(image, ans, sr, sc, color, iniColor);
      

        return ans;
    }
};