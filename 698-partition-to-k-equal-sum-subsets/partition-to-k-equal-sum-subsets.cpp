class Solution {
public:
    unordered_map<int, bool> mp;
    bool helper(vector<int>& nums, int k, int currSum, int mask, int target) {
        if(k == 0)
            return true;
        
        if(currSum == target)
            return helper(nums, k - 1, 0, mask, target);
        
        if(mp.find(mask) != mp.end())
            return mp[mask];
        
        bool result = false;

        for(int i = 0; i < nums.size(); i++) {
            if(mask & (1 << i))
                continue;
            
            if(currSum + nums[i] > target)
                continue;
            
            result = helper(nums, k, currSum + nums[i], mask | (1 << i), target);

            if(result)
                break;
        }

        return mp[mask] = result;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++) 
            total += nums[i];
        
        if(total % k != 0) return false;
        int target = total / k;
        return helper(nums, k, 0, 0, target);   
    }
};