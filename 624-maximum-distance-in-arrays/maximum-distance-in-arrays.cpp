class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        
        for (int i = 1; i < arrays.size(); i++) {
            int n = arrays[i].size();

            result = max(result, abs(arrays[i][n - 1] - minVal));
            result = max(result, abs(maxVal - arrays[i][0]));
            
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i][n - 1]);
        }
        
        return result;
    }
};