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


    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> sorted_rating = rating;
        sort(sorted_rating.begin(), sorted_rating.end());
        vector<int> ca(n);
        for(int i = 0; i < n; i++) 
            ca[i] = lower_bound(sorted_rating.begin(), sorted_rating.end(), rating[i]) - sorted_rating.begin() + 1;
        
        SEGTree seg1(n);
        int ans = 0;
        vector<int> lft1(n), lft2(n);
        for(int i = 0; i < n; i++) {
            int tmp1 = seg1.query(1, ca[i] - 1);
            int tmp2 = seg1.query(ca[i] + 1, n);
            lft1[i] = tmp1;
            lft2[i] = tmp2;

            seg1.update(ca[i]);
        }

        SEGTree seg2(n);
        vector<int> rht1(n), rht2(n);
        for(int i = n - 1; i >= 0; i--) {
            int tmp1 = seg2.query(ca[i] + 1, n);
            int tmp2 = seg2.query(1, ca[i] - 1);
            rht1[i] = tmp1;
            rht2[i] = tmp2;

            seg2.update(ca[i]);
        }

        for(int i = 0; i < n; i++) {
            ans += lft1[i] * rht1[i];
            ans += lft2[i] * rht2[i];
        }

        return ans;
    }
};

