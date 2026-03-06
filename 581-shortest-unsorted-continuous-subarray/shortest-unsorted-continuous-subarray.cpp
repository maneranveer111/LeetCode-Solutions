class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int i = 0, j = nums.size() - 1;
        int len = 0;
        while(i <= j) {
            if(temp[i] != nums[i] && temp[j] != nums[j]) {
                len = j - i;
                break;
            }

            if(temp[i] == nums[i]) i++;
            if(temp[j] == nums[j]) j--; 
        }   

        return (len == 0) ? 0 : len + 1;
    }
};