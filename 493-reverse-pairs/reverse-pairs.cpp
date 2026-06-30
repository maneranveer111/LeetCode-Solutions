class Solution {
public:
    class SEGTree {
        vector<int> tree;
        int n;
    public:
        SEGTree(int n) : n(n), tree(4 * n) {};

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

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        SEGTree seg(n);
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> ca(n);

        for(int j = 0; j < nums.size(); j++)
            ca[j] = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[j]) - sorted_nums.begin() + 1;

        for(int j = 0; j < nums.size(); j++) {
            long long nm = (long long)nums[j] * 2;
            int nmi = upper_bound(sorted_nums.begin(), sorted_nums.end(), nm) - sorted_nums.begin() + 1;
            
            ans += seg.query(nmi, n);
            seg.update(ca[j]);
        }
             
        return ans;
    }
};

