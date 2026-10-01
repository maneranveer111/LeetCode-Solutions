class Solution {
public: 
    vector<int> prefix;
    vector<int> ans;
    int n, k;
    
    vector<vector<int>> memo;

    int  helper(int idx, int cnt) {
        if(cnt == 0)
            return 0; 
        if(idx + k > n)
            return INT_MIN / 2;
        
        if(memo[idx][cnt] != -1)
            return memo[idx][cnt];
        
        int take = helper(idx + k, cnt - 1) + prefix[idx + k] - prefix[idx];
        int skip = helper(idx + 1, cnt);

        return memo[idx][cnt] = max(take, skip);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
        k = K;
        n = nums.size();
        prefix.assign(n + 1, 0);

        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        
        memo.assign(n, vector<int>(4, -1));
        helper(0, 3);
        
        vector<int> ans;
        int idx = 0, cnt = 3;

        while(cnt) {
            int take = INT_MIN / 2;
            
            if(idx + k <= n) {
                take = helper(idx + k, cnt - 1) + prefix[idx + k] - prefix[idx];
            }
            int skip = helper(idx + 1, cnt);

            if(take >= skip) {
                ans.push_back(idx);
                idx += k;
                cnt--;
            }
            else 
                idx++;
        }

        return ans;
    }
};