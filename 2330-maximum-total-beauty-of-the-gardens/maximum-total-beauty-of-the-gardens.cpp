class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlower, int target, int full, int partial) {
        int n = flowers.size();
        sort(flowers.begin(), flowers.end());

        for(int i = 0; i < n; i++)
            flowers[i] = min(flowers[i], target);

        int makeFull = (int)(lower_bound(flowers.begin(), flowers.end(), target) - flowers.begin());
        int freeFull = n - makeFull;

        vector<long long> pre(n + 1, 0);  
        for(int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + flowers[i];

        long long ans = 0;

        for(int j = 0; j <= makeFull; j++) {
            long long spent = (long long)target * j - (pre[makeFull] - pre[makeFull - j]);
            if(spent > newFlower) break;

            long long rem = newFlower - spent;
            int incIdx = makeFull - j;
            int totalFull = j + freeFull;

            if(incIdx == 0) {
                ans = max(ans, (long long)totalFull * full);
                continue;
            }

            long long lo = 0, hi = min((long long)(target - 1), flowers[incIdx - 1] + rem);

            while(lo < hi) {
                long long mid = lo + (hi - lo + 1) / 2;  
                
                int pos = (int)(lower_bound(flowers.begin(), flowers.begin() + incIdx, mid) - flowers.begin());
                long long cost = mid * pos - pre[pos];
                if(cost <= rem) lo = mid;
                else hi = mid - 1;
            }

            ans = max(ans, (long long)totalFull * full + lo * partial);
        }

        return ans;
    }
};