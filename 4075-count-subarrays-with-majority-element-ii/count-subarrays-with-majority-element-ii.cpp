class Solution {
public:
    vector<long long> seg;
    int sz;
    
    void build(int n) {
        sz = n;
        seg.assign(4 * n, 0);
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            seg[node] += val;
            return;
        }

        int mid = (start + end) / 2;
        if(idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
            
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    
    long long query(int node, int start, int end, int l, int r) {
        if(r < start || end < l) 
            return 0;
        if(l <= start && end <= r)
            return seg[node];
            
        int mid = (start + end) / 2;
        
        return query(2*node, start, mid, l, r) +
               query(2*node+1, mid+1, end, l, r);
    }
    
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
            nums[i] = (nums[i] == target) ? 1 : -1;
        
        int offset = n;
        build(2 * n + 1);
        
        long long sum = 0, cnt = 0;
        
        update(1, 0, sz-1, 0 + offset, 1);
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            int need = (sum - 1) + offset;
            
            if(need >= 0)
                cnt += query(1, 0, sz-1, 0, min(need, sz-1));
            
            update(1, 0, sz-1, sum + offset, 1);
        }
        
        return cnt;
    }
};