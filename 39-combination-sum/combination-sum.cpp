class Solution {
public:
    vector<int> ds;
    vector<vector<int>> ans;
    void helper(int idx, vector<int>& arr, int target){
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        if(idx >= arr.size())
            return;

        if(target >= arr[idx]) {
            ds.push_back(arr[idx]);
            helper(idx, arr, target - arr[idx]);
            ds.pop_back();
        }

        helper(idx + 1, arr, target);

    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
       
       helper(0, arr, target);

       return ans;
    }
};