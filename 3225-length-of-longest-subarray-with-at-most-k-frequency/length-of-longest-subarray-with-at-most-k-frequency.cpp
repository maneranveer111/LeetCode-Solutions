class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int lft = 0;
        unordered_map<int, int> mp;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;

            if(mp[nums[i]] > k) {
                while(lft < i && mp[nums[i]] > k) {
                    mp[nums[lft]]--;
                    lft++;
                }
            }

            ans = max(ans, i - lft + 1);
        }

        return ans;
    }
};