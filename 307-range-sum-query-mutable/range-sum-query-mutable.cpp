class NumArray {
public:
    class SEGTree{
    public:
        vector<int> tree;
        int n;
        SEGTree();
        SEGTree(int n) : n(n), tree(4 * n) {};

        void updateSEG(int idx, int l, int r, int pos, int val) {
            if(l == r) {
                tree[idx] = val;
                return;
            }

            int mid = l + (r - l) / 2;
            if(pos <= mid)
                updateSEG(2 * idx + 1, l, mid, pos, val);
            else
                updateSEG(2 * idx + 2, mid + 1, r, pos, val);

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

        void updateSEG(int pos, int val) {
            updateSEG(0, 0, n - 1, pos, val);
        }

        int query(int st, int en) {return (st > en) ? 0 : query(0, 0, n - 1, st, en);}
    };

    SEGTree seg;
    vector<int> nums;

    NumArray(vector<int>& nums) : nums(nums), seg(nums.size()) {
        for (int i = 0; i < (int)nums.size(); i++)
            seg.updateSEG(i, nums[i]);
    }
    
    void update(int index, int val) {
        nums[index] = val;
        seg.updateSEG(index, val);
    }
    
    int sumRange(int left, int right) {
        return seg.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */