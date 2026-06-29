class Solution {
public:
    class SEGTree{
        vector<int> tree;
        int n;

    public:
        SEGTree(int n) : n(n), tree(4 * n, 0) {};

        void update(int idx, int l, int r, int pos) {
            if(l == r) {
                tree[idx]++;
                return;
            }

            int mid = l + (r - l) / 2;

            if(pos <= mid) 
                update(2 * idx + 1, l, mid, pos);
            else
                update(2 * idx + 2, mid + 1, r, pos);
            
            tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
        }

        int query(int idx, int l, int r, int st, int en) {
            if(en < l || st > r)    
                return 0;
            
            if(st <= l && r <= en)
                return tree[idx];

            int mid = l + (r - l) / 2;
            int lft = query(2 * idx + 1, l, mid, st, en);
            int rht = query(2 * idx + 2, mid + 1, r, st, en);

            return lft + rht;
        }

        void update(int pos) {update(0, 1, n, pos);}
        int query(int st, int en) {return (st > en) ? 0 : query(0, 1, n, st, en);}
    };

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) 
            prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> sorted_prefix = prefix;
        sort(sorted_prefix.begin(), sorted_prefix.end());
        sorted_prefix.erase(unique(sorted_prefix.begin(), sorted_prefix.end()), sorted_prefix.end());
        int m = sorted_prefix.size();

        auto compress = [&](long long val) {
            return lower_bound(sorted_prefix.begin(), sorted_prefix.end(), val) - sorted_prefix.begin() + 1;
        };

        SEGTree seg(m);
        int ans = 0;

        for(int i = 0; i <= n; i++) {
            long long lo = prefix[i] - upper;
            long long hi = prefix[i] - lower;

            int clo = lower_bound(sorted_prefix.begin(), sorted_prefix.end(), lo) - sorted_prefix.begin() + 1;
            int chi = upper_bound(sorted_prefix.begin(), sorted_prefix.end(), hi) - sorted_prefix.begin();

            ans += seg.query(clo, chi);
            seg.update(compress(prefix[i]));
        }

        return ans;
    }
};