class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        dis[0][0] = 0; 
        pq.push({0, 0, 0});

        while(!pq.empty()) {
            auto tm = pq.top();
            pq.pop();

            int eff = tm[0], r = tm[1], c = tm[2];
            if(r == m - 1 && c == n - 1)
                return eff;

            for(int i = 0; i < 4; i++) {
                int nr = dx[i] + r;
                int nc = dy[i] + c;
                
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int neff = max(eff, abs(heights[r][c] - heights[nr][nc]));
                    if(neff < dis[nr][nc]) {
                        dis[nr][nc] = neff;
                        pq.push({neff, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};