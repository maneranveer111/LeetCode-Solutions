class Solution {
public:
    class SEGTree {
        vector<int> tree;
        int n;
    public:
        SEGTree(int n) : n(n), tree(4 * n) {};

        int merge(int l1, int l2) {
            if(l1 > l2)
                return l1;
            else
                return l2;
        }

        void update(int idx, int l, int r, int len, int pos) {
            if(l == r) {
                if(len > tree[idx])
                    tree[idx] = len;
                return;
            }

            int mid = l + (r - l) / 2;
            if(pos <= mid)
                update(2 * idx + 1, l, mid, len, pos);
            else
                update(2 * idx + 2, mid + 1, r, len, pos);

            tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
        }

        int query(int idx, int l, int r, int st, int en) {
            if(en < l || st > r)
                return 0;
            if(st <= l && r <= en)
                return tree[idx];

            int mid = l + (r - l) / 2;
            int lft = query(2 * idx + 1, l, mid, st, en);
            int rht = query(2 * idx + 2, mid + 1, r, st, en);

            return merge(lft, rht);
        }
        
        void update(int len, int pos) {
            update(0, 1, n, len, pos);
        }
        
        int query(int st, int en) {
            return (st > en) ? 0 : query(0, 1, n, st, en);
        }
    };

    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sorted_num = nums;
        sort(sorted_num.begin(), sorted_num.end());
        vector<int> ca(n);

        for(int i = 0; i < n; i++) 
            ca[i] = (lower_bound(sorted_num.begin(), sorted_num.end(), nums[i]) - sorted_num.begin()) + 1;
        
        SEGTree seg(n);

        int len = 0;
        for(int j = 0; j < n; j++) {
            int l = (lower_bound(sorted_num.begin(), sorted_num.end(), nums[j] - k) - sorted_num.begin()) + 1;
            int r = (upper_bound(sorted_num.begin(), sorted_num.end(), nums[j] - 1) - sorted_num.begin());
            int q = seg.query(l, r);

            if(q == 0)
                len = 1;
            else 
                len = q + 1;
            
            seg.update(len, ca[j]);
        }

        return seg.query(1, n);
    }
};

