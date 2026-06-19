class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];

        int minEle = *min_element(nums.begin(), nums.end());

        int moves = sum - (n * minEle);

        return moves;
    }
};