class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == k)
            return *max_element(nums.begin(), nums.end());

        unordered_map<int, int> mp;

        for(int x : nums)
            mp[x]++;
        
        if(k == 1) {
            int ans = -1;
            for(auto [key, val] : mp) {
                if(val == 1)
                    ans = max(ans, key);
            }

            return ans;
        }
        int ans = -1;

        if (mp[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (mp[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};
