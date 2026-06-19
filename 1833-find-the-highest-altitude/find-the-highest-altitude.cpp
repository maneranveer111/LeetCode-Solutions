class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, ans = INT_MIN;

        for(int i = 0; i < gain.size(); i++) {
            sum += gain[i];
            ans = max(ans, sum);
        }

        return (ans < 0) ? 0 : ans;
    }
};