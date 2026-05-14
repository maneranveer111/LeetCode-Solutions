class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> idx(heights.size());
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&heights](int i, int j) {
            return heights[i] > heights[j];
        });

        vector<string> ans(heights.size());

        for(int i = 0; i < heights.size(); i++) {
            ans[i] = names[idx[i]];
        }

        return ans;
    }
};