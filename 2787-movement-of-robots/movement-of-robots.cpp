class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> pos(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R')
                pos[i] = (long long)nums[i] + d; 
            else
                pos[i] = (long long)nums[i] - d;
        }

        sort(pos.begin(), pos.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long temp = (pos[i] % MOD) * ((2LL * i - n + 1) % MOD) % MOD;
            ans = (ans + temp) % MOD;
        }

        return (int)((ans % MOD + MOD) % MOD);
    }
};