class Solution {
public:
    unordered_map<string, bool> mp;

    bool helper(vector<int>& nums, long long idx, long long curr, long long target) {
        if(curr == target)
            return true;
        if(idx >= (long long)nums.size())
            return false;
        if(curr > target)
            return false;

        string key = to_string(idx) + "#" + to_string(curr);
        if(mp.find(key) != mp.end())
            return mp[key];

        bool take = false;
        if(curr <= target / nums[idx])
            take = helper(nums, idx + 1, curr * nums[idx], target);
        if(take)
            return mp[key] = true;

        bool skip = helper(nums, idx + 1, curr, target);
        return mp[key] = skip;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        mp.clear();
        
        __int128 pro = 1;
        for(int i : nums) pro *= i;

        __int128 t = target;
        if(pro % t != 0 || pro / t != t)
            return false;

        return helper(nums, 0, 1, target);
    }
};