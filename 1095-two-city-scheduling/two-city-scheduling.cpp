class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        
        sort(costs.begin(), costs.end(), [](const vector<int>& x, const vector<int>& y) {
            return (x[0] - x[1]) < (y[0] - y[1]);
        });
        
        int total = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (i < n)
                total += costs[i][0];
            else
                total += costs[i][1];
        }
        
        return total;
    }
};