class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        sort(flowers.begin(), flowers.end());

        for (int i = 0; i < n; i++)
            flowers[i] = min(flowers[i], target);

        // Count gardens already complete (= target after capping)
        // Since sorted ascending, find first index at target
        int alreadyFull = (int)(lower_bound(flowers.begin(), flowers.end(), target)
                                - flowers.begin());
        // alreadyFull = number of gardens with flowers[i] < target
        // so already complete = n - alreadyFull
        int baseFull = n - alreadyFull; // free complete gardens, cost nothing

        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + flowers[i];

        long long ans = 0;

        // j = additional gardens we choose to make complete (from the non-full ones)
        // j ranges over [0, alreadyFull] since only non-full gardens need spending
        for (int j = 0; j <= alreadyFull; j++) {
            // Pick the j largest among the incomplete gardens (indices alreadyFull-j .. alreadyFull-1)
            long long spent = (long long)target * j 
                              - (pre[alreadyFull] - pre[alreadyFull - j]);
            if (spent > newFlowers) break;

            long long rem = newFlowers - spent;
            int incIdx = alreadyFull - j; // remaining incomplete gardens
            int totalFull = baseFull + j;  // total complete gardens

            if (incIdx == 0) {
                ans = max(ans, (long long)totalFull * full);
                continue;
            }

            // Binary search for max achievable minimum across incomplete gardens
            long long lo = 0, hi = min((long long)(target - 1),
                                       flowers[incIdx - 1] + rem);

            while (lo < hi) {
                long long mid = lo + (hi - lo + 1) / 2;
                int pos = (int)(lower_bound(flowers.begin(),
                                            flowers.begin() + incIdx, mid)
                                - flowers.begin());
                long long cost = mid * pos - pre[pos];
                if (cost <= rem) lo = mid;
                else hi = mid - 1;
            }

            ans = max(ans, (long long)totalFull * full + lo * partial);
        }

        return ans;
    }
};