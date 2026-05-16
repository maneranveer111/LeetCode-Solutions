class Solution {
public:
    int findMin(vector<int>& nums) {
        // int n = nums.size();
        // int lft = 0, rht = n - 1;

        // while(lft < rht) {
        //     int mid = lft + (rht - lft) / 2;
            
        //     while(nums[lft] == nums[rht]) {
        //         lft++;
        //         rht--;
        //         if(lft >= rht)
        //             return nums[rht];
        //     }

        //     if(nums[mid] > nums[rht] && nums[mid] > nums[lft]) {
        //         lft = mid + 1;
        //     }
        //     else if(nums[mid] < nums[rht] && nums[mid] <nums[lft]) {
        //         rht = mid;
        //     }
        //     else if(nums[mid] > nums[rht] ) lft = mid + 1;
        //     else rht = mid;
        // }

        // return nums[lft];

        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i]); 
        }

        return mini;
    }
};