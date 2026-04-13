class Solution {
public:
    vector<vector<int>> store;
    map<int, int> mp;
    int cnt = 0;

    void helper(vector<int>& nums, int k, int idx) {
        
        for(int i = idx; i < nums.size(); i++) {
            if(mp[nums[i] - k] > 0 || mp[nums[i] + k] > 0) 
                continue;
            mp[nums[i]]++;
            cnt++;
            helper(nums, k, i + 1);
            mp[nums[i]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        cnt = 0;
        mp.clear();
        helper(nums, k, 0);

        return cnt;
    }
};