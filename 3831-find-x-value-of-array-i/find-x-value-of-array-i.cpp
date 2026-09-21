class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0), cnt(k, 0);
        for (int v : nums) {
            vector<long long> next(k, 0);
            int vm = v % k;
            for (int r = 0; r < k; r++) {
                if (cnt[r]) next[(r * vm) % k] += cnt[r];
            }
            next[vm] += 1;   
            cnt = next;
            for (int r = 0; r < k; r++) res[r] += cnt[r];
        }
        return res;
    }
};