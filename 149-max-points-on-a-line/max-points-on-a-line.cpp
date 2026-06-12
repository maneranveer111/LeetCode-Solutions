class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return n;
        int ans = 2;

        for(int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            for(int j = 0; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = __gcd(abs(dx), abs(dy));

                if(g == 0)
                    continue;
                dx /= g;
                dy /= g;
                
                if(dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                else if (dx == 0) 
                    dy = abs(dy);
                
                mp[{dy, dx}]++;
            }

            for (auto& [slp, cnt] : mp)
                ans = max(ans, cnt + 1);
        } 

        return ans;   
    }
};