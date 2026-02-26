class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ele = -1;
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if((mid + 1 < n && nums[mid] == nums[mid + 1])) {
                if((high - mid + 1) % 2 == 0) high = mid - 1;
                else low = mid + 2;
            }
            else if((mid - 1 >= 0 && nums[mid] == nums[mid - 1])) {
                if((high - mid) % 2 == 0) high = mid - 2;
                else low = mid + 1;
            }
            else return nums[mid];
        }

        return -1;
    }
};