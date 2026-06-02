class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        vector<pair<int, int>> land(n), water(m);
        
        for(int i = 0; i < n; i++) {
            land[i] = {landStartTime[i], landDuration[i]};
        }

        for(int j = 0; j < m; j++)
            water[j] = {waterStartTime[j], waterDuration[j]};
        
        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            int a = land[i].first;
            int b = land[i].second;
            int best = INT_MAX;
            for(int j = 0; j < m; j++) {
                // time += a + b;
                int time = max(0, a) + b;
                if(time <= water[j].first)
                    time = water[j].first + water[j].second;
                else {
                    time += water[j].second;
                }

                best = min(best, time);
            }

            ans = min(ans, best);
        }

        for(int i = 0; i < m; i++) {
            int a = water[i].first;
            int b = water[i].second;
            int best = INT_MAX;
            for(int j = 0; j < n; j++) {
                // time += a + b;
                int time = max(0, a) + b;
                if(time <= land[j].first)
                    time = land[j].first + land[j].second;
                else {
                    time += land[j].second;
                }

                best = min(best, time);
            }

            ans = min(ans, best);
        }

        return ans;
        
    }
};

