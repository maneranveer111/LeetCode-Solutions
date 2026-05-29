class Solution {
public:
    int minElement(vector<int>& nums) {
        int minNum = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            while(nums[i]) {
                int last = nums[i] % 10;
                nums[i] /= 10;
                sum += last;
            }

            minNum = min(minNum, sum);
        }

        return minNum;
    }
};