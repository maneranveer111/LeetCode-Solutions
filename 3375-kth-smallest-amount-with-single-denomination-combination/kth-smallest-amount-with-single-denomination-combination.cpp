class Solution {
public:
    vector<pair<long long, int>> preLCM;
    int n;

    void preCoumputeLCM(vector<int>& coins) {
        for(int mask = 1; mask < (1 << n); mask++) {
            int bits = 0;
            long long lcm = 1;
            bool overFlow = false;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    long long gcd = __gcd(lcm, (long long)coins[i]);

                    if(lcm / gcd > (long long)2e18) {
                        overFlow = true;
                        break;
                    } 

                    lcm = lcm / gcd * coins[i];
                    bits++;
                }
            }

            if(overFlow)
                continue;
            int sign = (bits % 2 == 0) ? -1 : 1;
            preLCM.push_back({lcm, sign});
        }
    }

    long long lessThanOrEqualtoX(long long mid) {
        long long total = 0;
        for(auto [lcm, sign] : preLCM) {
            total += sign * (mid / lcm);
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        n = coins.size();
        long long low = *min_element(coins.begin(), coins.end());
        long long hi = (long long)*min_element(coins.begin(), coins.end()) * k;
        long long ans = hi;

        preCoumputeLCM(coins);

        while(low <= hi) {
            long long mid = low + (hi - low) / 2;

            if(lessThanOrEqualtoX(mid) >= k) {
                ans = mid;
                hi = mid - 1;
            } 
            else
                low = mid + 1;
        }

        return ans;
    }
};