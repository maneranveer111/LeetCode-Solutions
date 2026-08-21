class Solution {
public:
    long long findLessThanOrEqual(long long mid, int m, int n) {
        long long total = 0;
        for(int i = 1; i <= m; i++) {
            total += min((long long)n, mid / i);
        }

        return total;
    }

    int findKthNumber(int m, int n, int k) {
        long long lo = 1, hi = m * n; 
        long long ans = hi;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(findLessThanOrEqual(mid, m, n) >= k) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        
        return ans;
    }
};