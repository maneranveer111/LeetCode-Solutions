class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; 
            }
            return a[0] < b[0];    
        });
        
        pair<int, int> prev = {intervals[0][0], intervals[0][1]};
        int cnt = 1;

        for(int i = 1; i < intervals.size(); i++) {
            if(prev.first <= intervals[i][0] && intervals[i][1] <= prev.second)
                continue;
            else {
                cnt++;
                prev.first = min(intervals[i][0], prev.first);  
                prev.second = max(intervals[i][1], prev.second);
            }
        }
        
        return cnt;
    }
};