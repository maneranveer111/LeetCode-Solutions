class Solution {
public:
    int helper(vector<int>& cookies, vector<int>& child, int idx, int mid, int k) {
        if(idx == cookies.size())
            return true;
        
        for(int i = 0; i < k; i++) {
            if(child[i] + cookies[idx] <= mid) {
                child[i] += cookies[idx];
                if(helper(cookies, child, idx + 1, mid, k))
                    return true;
                child[i] -= cookies[idx];
            }

            if(child[i] == 0)
                break;
        }

        return false;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int lo = INT_MIN, hi = 0;
        for(int i = 0; i < n; i++) {
            lo = max(lo, cookies[i]);
            hi += cookies[i];
        }

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            vector<int> child(k, 0);
            
            if(helper(cookies, child, 0, mid, k))
                hi = mid - 1;
            else 
                lo = mid + 1;
        }

        return lo;
    }
};


