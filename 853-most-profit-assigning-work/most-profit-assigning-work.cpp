class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> difProf(n);

        for(int i = 0; i < n; i++) {
            difProf[i].first = difficulty[i];
            difProf[i].second = profit[i];
        }

        sort(difProf.begin(), difProf.end());
        sort(worker.begin(), worker.end());
        int m = worker.size();

        vector<int> maxWork(m);
        int i = 0;
        int maxProfit = 0;

        for(int j = 0; j < m; j++) {
            int dif = worker[j];

            while(i < n && difProf[i].first <= dif) {
                maxProfit = max(maxProfit, difProf[i].second);
                i++;
            }

            maxWork[j] = maxProfit;
        }

        int ans = 0;
        for(int x : maxWork)
            ans += x;

        return ans;
    }
};