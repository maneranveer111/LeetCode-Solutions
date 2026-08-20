class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, double>> qByw(n);

        for(int i = 0; i < n; i++) {
            qByw[i].first = quality[i];
            qByw[i].second = wage[i];
        }

        sort(qByw.begin(), qByw.end(), [](auto a, auto b) {
            return a.first / a.second < b.first / b.second;
        });

        double ans = std::numeric_limits<double>::max();
        
        priority_queue<double> maxHeap; 
        double qualitySum = 0;

        for(int i = n - 1; i >= 0; i--) {
            double q = qByw[i].first;
            double w = qByw[i].second;

            maxHeap.push(q);
            qualitySum += q;

            if(maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }

            if(maxHeap.size() == k) {
                double ratio = w / q;
                ans = min(ans, ratio * qualitySum);
            } 
        }

        return ans;
    }
};

