class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int j = -1;
        vector<int> temp = nums;
        for(int i = 0; i < nums.size(); i++) {
            if(temp[i] < pivot) {
                j++;
                nums[j] = temp[i];
            }
        }

        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == pivot) {
                j++;
                nums[j] = temp[i];
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(temp[i] > pivot) {
                j++;
                nums[j] = temp[i];
            }
        }

        return nums;
    }
};