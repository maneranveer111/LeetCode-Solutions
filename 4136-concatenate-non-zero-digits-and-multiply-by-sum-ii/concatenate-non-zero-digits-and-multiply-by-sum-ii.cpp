class Solution {
public:
    static const long long MOD = 1e9 + 7;

    class SEGTree {
    public:
        int n;
        vector<long long> val, cnt, sum;
        vector<long long>& pow10;

        SEGTree(int n, vector<long long>& pow10)
            : n(n), val(4 * n, 0), cnt(4 * n, 0), sum(4 * n, 0), pow10(pow10) {}

        void build(int idx, int l, int r, string& s) {
            if (l == r) {
                int dig = s[l] - '0';
                if (dig == 0) {
                    val[idx] = 0;
                    cnt[idx] = 0;
                    sum[idx] = 0;
                } else {
                    val[idx] = dig;
                    cnt[idx] = 1;
                    sum[idx] = dig;
                }
                return;
            }

            int mid = l + (r - l) / 2;
            build(2 * idx, l, mid, s);
            build(2 * idx + 1, mid + 1, r, s);
            merge(idx, 2 * idx, 2 * idx + 1);
        }

        void merge(int idx, int leftIdx, int rightIdx) {
            cnt[idx] = cnt[leftIdx] + cnt[rightIdx];
            sum[idx] = sum[leftIdx] + sum[rightIdx];
            val[idx] = (val[leftIdx] * pow10[cnt[rightIdx]] % MOD + val[rightIdx]) % MOD;
        }

        array<long long, 3> query(int idx, int l, int r, int st, int en) {
            if (st <= l && r <= en) {
                return {val[idx], cnt[idx], sum[idx]};
            }

            int mid = l + (r - l) / 2;

            if (en <= mid) return query(2 * idx, l, mid, st, en);
            if (st > mid) return query(2 * idx + 1, mid + 1, r, st, en);

            auto leftRes = query(2 * idx, l, mid, st, en);
            auto rightRes = query(2 * idx + 1, mid + 1, r, st, en);

            long long rCnt = rightRes[1];
            long long mergedVal = (leftRes[0] * pow10[rCnt] % MOD + rightRes[0]) % MOD;
            long long mergedCnt = leftRes[1] + rightRes[1];
            long long mergedSum = leftRes[2] + rightRes[2];

            return {mergedVal, mergedCnt, mergedSum};
        }
    };

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) pow10[i] = pow10[i - 1] * 10 % MOD;

        SEGTree seg(n, pow10);
        seg.build(1, 0, n - 1, s);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            auto res = seg.query(1, 0, n - 1, l, r);
            long long x = res[0];
            long long sm = res[2];
            long long answer = (x % MOD) * (sm % MOD) % MOD;
            ans.push_back((int)answer);
        }

        return ans;
    }
};