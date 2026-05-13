class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int n = tasks.size();
        int ans = 0, curr = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans = tasks[i][1];
                curr = tasks[i][1] - tasks[i][0];
            }
            else {
                if(curr < tasks[i][1]) {
                    ans += (tasks[i][1] - curr);
                    curr = tasks[i][1] - tasks[i][0];
                } 
                else {
                    curr -= tasks[i][0];
                }
            }
        }

        return ans;
    }
};