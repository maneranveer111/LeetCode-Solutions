class Solution {
public:
    int helper(vector<vector<int>>& series, int tar) {
        int low = 0, high = (int)series.size() - 1;
        int idx = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(series[mid][0] >= tar) {
                idx = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return (idx == -1) ? 0 : series[idx][1];
    }
    
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int i = 0;
        int l1 = series1.size(), l2 = series2.size();
        
        vector<int> time;
        for(auto arr : series1)
            time.push_back(arr[0]);
        for(auto arr : series2)
            time.push_back(arr[0]);

        sort(time.begin(), time.end());
        time.erase(unique(time.begin(), time.end()), time.end());

        vector<vector<int>> res;

        for(int i = 0; i < time.size(); i++) {
            int v1 = helper(series1, time[i]);
            int v2 = helper(series2, time[i]);

            res.push_back({time[i], v1 + v2});
        }

        return res;
    }
};
