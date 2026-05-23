class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        // for(int i = 0; i < nums.size(); i++) {
        //     mini = min(mini, nums[i]);
        //     maxi = max(maxi, nums[i]);
        // }

        for(int i = 1; i < nums.size(); i++) {
            if(cnt == 0) {
                if(nums[i] >= nums[i - 1] && nums[i] >= nums[0])
                    continue;
                else if(nums[i] < nums[i - 1])
                    cnt++;
                if(i == nums.size() - 1)
                    cout << "hi" << endl;
                if(i == nums.size() - 1 && cnt >= 1 && nums[i] > nums[0])
                    return false;
            } 
            else if(cnt >= 1) {
                if(nums[i] >= nums[i - 1] && nums[i] <= nums[0])
                    continue;
                else 
                    return false;
            }
            
        }

        return true;
    }
};