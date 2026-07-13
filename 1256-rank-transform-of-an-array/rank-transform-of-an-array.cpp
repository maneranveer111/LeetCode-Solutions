class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

        vector<int> ans(arr.size());

        for(int i = 0; i < arr.size(); i++) {
            ans[i] = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin() + 1;
        }

        return ans;
    }
};