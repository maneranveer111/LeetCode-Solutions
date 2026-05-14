class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxNum = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) 
            maxNum = max(maxNum, nums[i]);
        
        if(n != maxNum + 1)
            return false;
        
        int cnt = 1;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i != n - 1 && cnt == nums[i])
                cnt++;
            else if(i == n - 1 && cnt - 1 == nums[i])
                continue;
            else 
                return false;
        }

        return true;

    }
};