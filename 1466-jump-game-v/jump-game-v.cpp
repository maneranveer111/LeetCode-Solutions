class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& arr, int d, int idx) {
        int cnt = 0;
        if(idx >= arr.size() || idx < 0)    
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int forward = 0;
        for(int i = idx + 1; i <= idx + d && i < arr.size(); i++) {
            if(arr[i] >= arr[idx]) break;
                int temp = 1 + helper(arr, d, i);
                forward = max(forward, temp);
        }

        cnt = 0;
        int backward = 0;
        for(int i = idx - 1; i >= idx - d && i >= 0; i--) {
            if(arr[i] >= arr[idx]) break;
                int temp = 1 + helper(arr, d, i);
                backward = max(backward, temp);
            
        }

        return dp[idx] = max(forward, backward);
    }


    int maxJumps(vector<int>& arr, int d) {
        int ans = 0;
        int n = arr.size();
        dp.assign(n, -1);

        for(int i = 0; i < arr.size(); i++) {
            int a = helper(arr, d, i);
            ans = max(ans, a);
        }

        return ans + 1;
    }
};