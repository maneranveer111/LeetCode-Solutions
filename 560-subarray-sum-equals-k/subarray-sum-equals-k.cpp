class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, cnt = 0;
        mp[sum] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int need = sum - k;
            if(mp.find(need) != mp.end())
                cnt += mp[need];

            mp[sum]++;
        }

        return cnt;
    }
};