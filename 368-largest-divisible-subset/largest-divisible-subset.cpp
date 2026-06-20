class Solution {
public:
    // map<pair<int,int>, vector<int>> memo;
    
    // vector<int> solve(vector<int>& nums, int prev, int i) {
    //     if(i == nums.size()) return {};
        
    //     if(memo.count({i, prev})) return memo[{i, prev}];
        
    //     vector<int> skip = solve(nums, prev, i + 1);
    //     vector<int> take = {};
    //     if(prev == -1 || nums[i] % prev == 0) {
    //         take = solve(nums, nums[i], i + 1);
    //         take.insert(take.begin(), nums[i]);
    //     }
        
    //     return memo[{i, prev}] = (take.size() > skip.size()) ? take : skip;
    // }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());   
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> prevEle(n, -1);
        int maxIdx = 0, maxLen = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prevEle[i] = j;
                }
            }

            if(dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        vector<int> ans;
        for(int i = maxIdx; i != -1; i = prevEle[i])
            ans.push_back(nums[i]);
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};