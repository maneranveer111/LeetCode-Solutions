class Solution {
public:
    bool helper(int mid, int n, vector<int>& quantities) {
        int cnt = 0;

        for(int i = 0; i < quantities.size(); i++) {
            int tmp = quantities[i] % mid;
            if(tmp == 0)
                cnt += quantities[i] / mid;
            else
                cnt += quantities[i] / mid + 1;
        }

        return cnt <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1;
        int hi = *max_element(quantities.begin(), quantities.end());
        int ans = hi;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(helper(mid, n, quantities)) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return ans;
    }
};