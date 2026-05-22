class Solution {
public:
    
    string optimalDivision(vector<int>& nums) {
        string ans = "";
        if(nums.size() == 1)
            return to_string(nums[0]);
        if(nums.size() == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
            
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0)
                ans += to_string(nums[i]) + "/(";
            else if(i == nums.size() - 1) {
                ans += to_string(nums[i]) + ")";
            }
            else {
                ans += to_string(nums[i]) + "/";
            }
        }

        return ans;
    }
};