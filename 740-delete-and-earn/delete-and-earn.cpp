class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<long long> points(maxVal + 1, 0);

        for(int nm : nums) 
            points[nm] += nm;
        
        int take = 0, skip = 0;
        for(int i = 0; i <= maxVal; i++) {
            int newTake = points[i] + skip;
            int newSkip = max(take, skip);
            take = newTake;
            skip = newSkip;
        }

        return max(skip, take);
    }
};