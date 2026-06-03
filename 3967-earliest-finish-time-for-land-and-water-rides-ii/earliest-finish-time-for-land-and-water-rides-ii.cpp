class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minLand = INT_MAX, minWater = INT_MAX;

        for(int i = 0; i < n; i++) {
            minLand = min(minLand, landStartTime[i] + landDuration[i]);
        }

        for(int i = 0; i < m; i++) {
            minWater = min(minWater, waterStartTime[i] + waterDuration[i]);
        }
        int ans = INT_MAX;

        for(int j = 0; j < m; j++) {
            if(minLand >= waterStartTime[j]) {
                ans = min(ans, minLand + waterDuration[j]);
            }
            else 
                ans = min(ans, waterDuration[j] + waterStartTime[j]);
        }

        for(int i = 0; i < n; i++) {
            if(minWater >= landStartTime[i])
                ans = min(ans, minWater + landDuration[i]);
            else 
                ans = min(ans, landDuration[i] + landStartTime[i]);
        }

        return ans;
    }
};