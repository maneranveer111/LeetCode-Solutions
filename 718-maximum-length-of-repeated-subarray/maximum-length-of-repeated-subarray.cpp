class Solution {
public:
    vector<vector<int>> memo;
    
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i == nums1.size() || j == nums2.size())
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];

        int both = 0, move1 = 0, move2 = 0;

        if(nums1[i] == nums2[j])
            both = 1 + helper(i + 1, j + 1, nums1, nums2);


        return memo[i][j] = both;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;
        memo.assign(n, vector<int>(m, -1));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, helper(i, j, nums1, nums2));
            }
        }

        return ans;
    }
};