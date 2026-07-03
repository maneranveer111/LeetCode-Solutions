class Solution {
public:
    class SEGTree{
    public:
        int n; 
        vector<int> tree;
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

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());   
        vector<int> ca(n);

        for(int i = 0; i < n; i++)
            ca[i] = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
        
        SEGTree seg(n);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--) {
            int cnt = seg.query(1, ca[i] - 1);
            ans[i] = cnt;

            seg.update(ca[i]);
        }

        return ans;
    }
};