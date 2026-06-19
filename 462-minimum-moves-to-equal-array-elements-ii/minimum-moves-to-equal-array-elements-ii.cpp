class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = 0;

        if(n & 1) {
            mid = nums[n / 2];
        }        
        else 
            mid = (nums[n / 2 - 1] + nums[n / 2]) / 2;
        
        int moves = 0;
        for(int i : nums) {
            moves += abs(mid - i);
        } 

        return moves;
    }
};