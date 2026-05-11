class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 1 && nums[i] < 10) 
                ans.push_back(nums[i]);
            else {
                string temp = to_string(nums[i]);
                for(int j = 0; j < temp.size(); j++) 
                    ans.push_back(temp[j] - '0');
            }
        }

        return ans;
    }
};