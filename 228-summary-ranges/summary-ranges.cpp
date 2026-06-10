class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int st = i;

            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            if (nums[i] == nums[st]) {
                ans.push_back(to_string(nums[st]));          
            } else {
                ans.push_back(to_string(nums[st]) + "->" + to_string(nums[i])); 
            }

            i++;
        }

        return ans;
    }
};