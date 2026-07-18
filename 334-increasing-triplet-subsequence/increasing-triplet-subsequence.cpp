class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> forI(n, -1), forJ(n, -1);

        int mini = nums[0];
        for(int i = 1; i < n; i++) {
            if(mini < nums[i])
                forI[i] = 1;
            mini = min(mini, nums[i]);
        }

        int maxi = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(maxi > nums[i])
                forJ[i] = 1;
            maxi = max(maxi, nums[i]);
        }

        for(int i = 0; i < n; i++) 
            if(forJ[i] == 1 && forI[i] == 1)
                return true;
        
        return false;
    }
};