class Solution {
public:
    vector<int> memo;

    int helper(int idx, int k, vector<int>& arr) {
        if(idx == arr.size())
            return 0;
        if(memo[idx] != -1)
            return memo[idx];

        int currMax = -1;   
        int ans = INT_MIN;

        for(int i = idx; i - idx + 1 <= k && i < arr.size(); i++) {
            currMax = max(currMax, arr[i]);
            int curr = (i - idx + 1) * currMax + helper(i + 1, k, arr);
            ans = max(ans, curr);
        }

        return memo[idx] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memo.assign(n, -1);

        return helper(0, k, arr);  
    }
};