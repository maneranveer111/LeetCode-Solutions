class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int i = 1;

        while (i < n) {
            if (arr[i] == arr[i - 1]) {
                i++;
                continue;
            }

            int up = 0;
            while (i < n && arr[i] > arr[i - 1]) {
                up++;
                i++;
            }

            int down = 0;
            while (i < n && arr[i] < arr[i - 1]) {
                down++;
                i++;
            }

            if (up > 0 && down > 0)
                ans = max(ans, up + down + 1);
        }

        return ans;
    }
};