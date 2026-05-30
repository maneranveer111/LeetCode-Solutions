class Solution {
    static const int MAXV = 50001;
    int seg[4 * 50001];

    void update(int node, int lo, int hi, int pos, int val) {
        if (lo == hi) { seg[node] = val; return; }
        int mid = (lo + hi) / 2;
        if (pos <= mid) update(2*node, lo, mid, pos, val);
        else            update(2*node+1, mid+1, hi, pos, val);
        seg[node] = max(seg[2*node], seg[2*node+1]);
    }

    int query(int node, int lo, int hi, int l, int r) {
        if (r < lo || hi < l) return 0;
        if (l <= lo && hi <= r) return seg[node];
        int mid = (lo + hi) / 2;
        return max(query(2*node, lo, mid, l, r),
                   query(2*node+1, mid+1, hi, l, r));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obstacles;
        obstacles.insert(0);               // left sentinel
        memset(seg, 0, sizeof(seg));
        update(1, 0, MAXV, 0, 0);         // gap at position 0 = 0

        vector<bool> results;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto it  = obstacles.insert(x).first;
                auto nxt = std::next(it);
                auto prv = std::prev(it);

                // Gap stored AT x = distance from previous obstacle
                update(1, 0, MAXV, x, x - *prv);

                // Next obstacle's gap must be updated: it now measures from x
                if (nxt != obstacles.end())
                    update(1, 0, MAXV, *nxt, *nxt - x);

            } else {
                int x = q[1], sz = q[2];

                // Last obstacle <= x
                auto it   = obstacles.upper_bound(x);
                auto last = std::prev(it);

                // Trailing gap: from last obstacle to x
                int trailingGap = x - *last;

                // Max gap stored in seg tree over [0, x]
                int maxGap = max(query(1, 0, MAXV, 0, x), trailingGap);

                results.push_back(maxGap >= sz);
            }
        }                    // ← for loop closes here
        return results;      // ← outside the loop now
    }
};