class Solution {
public:
    class SEGTree{
        vector<pair<int,int>> tree;
        int n;

    public:
        SEGTree(int n) : n(n) , tree(4 * n) {};

        pair<int, int> merge(pair<int, int> t1, pair<int, int> t2) {
            if(t1.first > t2.first)
                return t1;
            
            if(t2.first > t1.first)
                return t2;

            return {t2.first, t1.second + t2.second};
        }

        pair<int, int> query(int idx, int l, int r, int st, int en) {
            if(en < l || st > r)
                return {0, 0};
            
            if(st <= l && r <= en)  
                return tree[idx];
            
            int mid = l + (r - l) / 2;
  
            pair<int, int> lft = query(2 * idx + 1, l, mid, st, en);
            pair<int, int> rht = query(2 * idx + 2, mid + 1, r, st, en);
            
            return merge(lft, rht);
        }

        void update(int idx, int l, int r, int pos, int len, int cnt) {
            if(l == r) {
                if(len > tree[idx].first) {
                    tree[idx].first = len;
                    tree[idx].second = cnt;
                }
                else if(len == tree[idx].first){
                    tree[idx].second += cnt;
                }
                return;
            }

            int mid = l + (r - l) / 2;

            if(pos <= mid) 
                update(2 * idx + 1, l, mid, pos, len, cnt);
            else 
                update(2 * idx + 2, mid + 1, r, pos, len, cnt);

            tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
        }

        void update(int pos, int len, int cnt) {
            update(0, 1, n, pos, len, cnt);
        }

        pair<int, int> query(int st, int en) {
            if(st > en)
                return {0, 0};
            return query(0, 1, n, st, en);
        }
    };

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_num = nums;
        sort(sorted_num.begin(), sorted_num.end());
        vector<int> ca(n);

        for(int i = 0; i < n; i++) 
            ca[i] = (lower_bound(sorted_num.begin(), sorted_num.end(), nums[i]) - sorted_num.begin()) + 1;
        
        SEGTree seg(n);
        int ans = 0, len = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            pair<int, int> tmp = seg.query(1, ca[i] - 1);

            if(tmp.first == 0) {
                len = 1;
                cnt = 1;
            }
            else {
                len = tmp.first + 1;
                cnt = tmp.second;
            }

            seg.update(ca[i], len, cnt);
        }

        ans = seg.query(1, n).second;

        return ans;
    }
};