class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int diff = 0, cnt = 0, lft = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]] == 0)
                diff++;
            mp[nums[i]]++;

            while(diff > k) {
                mp[nums[lft]]--;
                if(mp[nums[lft]] == 0)
                    diff--;
                lft++;
            }

            cnt += (i - lft + 1);
        }

        return cnt;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for(int i : nums)
            st.insert(i);
        int k = st.size();
        int c1 = helper(nums, k);
        int c2 = helper(nums, k - 1);

        return c1 - c2;  
    }
};