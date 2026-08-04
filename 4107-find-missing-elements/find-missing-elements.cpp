class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int start = nums[0] + 1;
        for (int i = 1; i < nums.size(); i++) {
            while (start < nums[i]) {
                ans.push_back(start);
                start++;
            }
            start = nums[i] + 1;
        }

        return ans;
    }
};