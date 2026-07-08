class Solution {
public:
    class SEGTree {
    public:
        int n;
        vector<int> tree;

        SEGTree(int n) : n(n), tree(4 * n, 0) {};

        void update(int idx, int l, int r, int i) {
            if(l == r) {
                tree[idx]++;
                return;
            }

            int mid = l + (r - l) / 2;
            if(i <= mid)
                update(2 * idx + 1, l, mid, i);
            else
                update(2 * idx + 2, mid + 1, r, i);

            tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
        }

        int query(int idx, int l, int r, int st, int en) {
            if(r < st || en < l)
                return 0;

            if(st <= l && r <= en)
                return tree[idx];
                
            int mid = l + (r - l) / 2;

            int lft = query(2 * idx + 1, l, mid, st, en);
            int rht = query(2 * idx + 2, mid + 1, r, st, en);
            
            return lft + rht;
        }

        void update(int idx) { update(0, 0, n-1, idx); }

        int query(int r) {
            if (r < 0) return 0;
            return query(0, 0, n-1, 0, r);
        }

    };

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<long long> a(n);
        for (int k = 0; k < n; k++) a[k] = (long long)nums1[k] - nums2[k];

        vector<long long> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());

        sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());
        int m = sorted_a.size();

        SEGTree seg(m);
        long long ans = 0;

        for(int j = 0; j < n; j++) {
            int limit = a[j] + diff;
            int rank = upper_bound(sorted_a.begin(), sorted_a.end(), limit) - sorted_a.begin();
            
            ans += seg.query(rank - 1);

            int pos = lower_bound(sorted_a.begin(), sorted_a.end(), a[j]) - sorted_a.begin();
            seg.update(pos);
        }

        return ans;
    }
};