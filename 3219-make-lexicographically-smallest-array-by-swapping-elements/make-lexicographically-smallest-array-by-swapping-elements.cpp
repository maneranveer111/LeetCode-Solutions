class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sortedIdx(n);

        iota(sortedIdx.begin(), sortedIdx.end(), 0);
        sort(sortedIdx.begin(), sortedIdx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> groupIdx;
        vector<int> groupVal;
        vector<int> result(n);

        for(int k = 0; k < n; k++) {
            int i = sortedIdx[k];

            if(k > 0 && nums[sortedIdx[k]] - nums[sortedIdx[k - 1]] > limit) {
                vector<int> sortGroup = groupIdx;
                sort(sortGroup.begin(), sortGroup.end());

                for(int j = 0; j < sortGroup.size(); j++) {
                    result[sortGroup[j]] = groupVal[j];
                }

                groupIdx.clear();
                groupVal.clear();
            }

            groupIdx.push_back(i);
            groupVal.push_back(nums[i]);
        }

        vector<int> sortGroup = groupIdx;
        sort(sortGroup.begin(), sortGroup.end());
        for(int j = 0; j < sortGroup.size(); j++) 
            result[sortGroup[j]] = groupVal[j];
        
        return result;
    }
};