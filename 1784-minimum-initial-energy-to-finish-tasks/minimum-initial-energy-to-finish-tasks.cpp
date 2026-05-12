class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort by (minimum - actual) descending
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int ans = 0, cur = 0;  // ans = answer so far, cur = current energy

        for (auto& t : tasks) {
            int actual = t[0], minimum = t[1];
            if (cur < minimum) {
                ans += minimum - cur;  // top up energy just enough
                cur = minimum;
            }
            cur -= actual;  // spend energy doing the task
        }

        return ans;
    }
};