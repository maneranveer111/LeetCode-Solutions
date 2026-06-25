class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }
        
        map<int, int> mp;
        int sum = 0, cnt = 0;
        mp[sum] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int need = sum - 1;
            
            auto ub = mp.upper_bound(need);
            for(auto it = mp.begin(); it != ub; ++it)
                cnt += it->second;
            
            mp[sum]++;
        }

        return cnt;
    }
};
