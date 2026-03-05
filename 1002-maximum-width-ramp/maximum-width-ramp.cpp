class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> idx(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            if(nums[i] == nums[j])
                return i < j;
            return nums[i] < nums[j];
        });

        int mini = idx[0];
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            ans = max(ans, idx[i] - mini);
            mini = min(mini, idx[i]);
        } 

        return ans;

    }
};