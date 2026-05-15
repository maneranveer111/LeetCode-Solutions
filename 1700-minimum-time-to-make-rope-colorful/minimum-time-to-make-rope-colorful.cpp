class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalCost = 0;
        int i = 0;
        while (i < n) {
            int j = i, sum = 0, mx = 0;
            while (j < n && colors[j] == colors[i]) {
                sum += neededTime[j];
                mx = max(mx, neededTime[j]);
                j++;
            }
            totalCost += (sum - mx);
            i = j;
        }
        return totalCost;
    }
};