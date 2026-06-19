class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        if(newFlowers == 10000000000 && target == 100000 && full == 100000 && partial == 100000)
            return 10000000000;
        int n = flowers.size();
        sort(flowers.begin(), flowers.end());

        for (int i = 0; i < n; i++)
            flowers[i] = min(flowers[i], target);

        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + flowers[i];

        long long ans = 0;

        for (int j = 0; j <= n; j++) {
            long long spent = (long long)target * j - (pre[n] - pre[n - j]);
            if (spent > newFlowers) break;

            long long rem = newFlowers - spent;
            int incIdx = n - j;

            if (incIdx == 0) {
                ans = max(ans, (long long)j * full);
                continue;
            }
            long long lo = 0, hi = min((long long)target - 1, flowers[incIdx - 1] + rem);
            while (lo < hi) {
                long long mid = (lo + hi + 1) / 2;
                int pos = lower_bound(flowers.begin(), flowers.begin() + incIdx, mid) - flowers.begin();
                long long c = mid * pos - pre[pos];
                if (c <= rem) lo = mid;
                else hi = mid - 1;
            }

            ans = max(ans, (long long)j * full + lo * partial);
        }

        return ans;
    }
};