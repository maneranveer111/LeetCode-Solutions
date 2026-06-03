class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        vector<pair<int, int>> land(n), water(m);
        
        for(int i = 0; i < n; i++)
            land[i] = {landStartTime[i], landDuration[i]};

        for(int j = 0; j < m; j++)
            water[j] = {waterStartTime[j], waterDuration[j]};
        
        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> prefixL;
        vector<int> prefixW;
        int till = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(!prefixL.empty()) {
                till = min(till, land[i].first + land[i].second);
                if(prefixL.back() != till)
                    prefixL.push_back(till);
            } else {
                prefixL.push_back(land[i].first + land[i].second);
                till = land[i].first + land[i].second;
            }
        }

        till = INT_MAX;
        for(int j = 0; j < m; j++) {
            if(!prefixW.empty()) {
                till = min(till, water[j].first + water[j].second);
                if(prefixW.back() != till)
                    prefixW.push_back(till);
            } else {
                prefixW.push_back(water[j].first + water[j].second);
                till = water[j].first + water[j].second;
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < (int)prefixL.size(); i++) {
            int best = INT_MAX;
            int time = prefixL[i];
            for(int j = 0; j < m; j++) {
                int cur = time;
                if(cur <= water[j].first)
                    cur = water[j].first + water[j].second;
                else
                    cur += water[j].second;
                best = min(best, cur);
            }
            ans = min(ans, best);
        }

        for(int i = 0; i < (int)prefixW.size(); i++) {
            int best = INT_MAX;
            int time = prefixW[i];
            for(int j = 0; j < n; j++) {
                int cur = time;
                if(cur <= land[j].first)
                    cur = land[j].first + land[j].second;
                else
                    cur += land[j].second;
                best = min(best, cur);
            }
            ans = min(ans, best);
        }

        return ans;
    }
};