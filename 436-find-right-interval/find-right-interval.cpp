class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> idx(intervals.size());
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&intervals](int i, int j){
            return intervals[i][0] < intervals[j][0];
        });   

        

        vector<int> ans(intervals.size());

        for(int i = 0; i < intervals.size(); i++) {
            int j = -1;

            int lft = 0, rht = idx.size() - 1;

            while(lft <= rht) {
                int mid = lft + (rht - lft) / 2;

                if(intervals[idx[mid]][0] >= intervals[i][1]) {
                    j = idx[mid];
                    rht = mid - 1;
                }
                else 
                    lft = mid + 1;
            }

            ans[i] = j;
        }

        return ans;
    }
};