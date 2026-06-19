class Solution {
public:
    bool helper(vector<int>& bloomDay, int m, int k, int mid) {
        int cnt = 0, i = 0;

        while(i < bloomDay.size()) {
            int j = i;
            while(j < bloomDay.size() && bloomDay[j] <= mid)
                j++;

            cnt += (j - i) / k;
            i = j;
            i++;
        }
        
        return cnt >= m;
    }
 
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(helper(bloomDay, m, k, mid)) {
                hi = mid - 1;
            }
            else 
                lo = mid + 1;
        }
        // int lo = *min_element(bloomDay.begin(), bloomDay.end());
        hi = *max_element(bloomDay.begin(), bloomDay.end());
        return (lo <= hi) ? lo : -1;
    }
};