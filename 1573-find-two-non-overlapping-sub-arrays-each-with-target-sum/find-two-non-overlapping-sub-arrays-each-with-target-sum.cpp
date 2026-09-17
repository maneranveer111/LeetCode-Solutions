class Solution {
public:
    vector<int> len;
    vector<vector<int>> memo;
    int n;

    int helper(int idx, int k) {
        if(k == 0)
            return 0;
        if(idx >= n)
            return INT_MAX;
        
        if(memo[idx][k] != -1)
            return memo[idx][k];
        
        int skip = helper(idx + 1, k);
        int take = INT_MAX;

        if(len[idx] != -1) {
            int rem = helper(idx + len[idx], k - 1);
            if(rem != INT_MAX)
                take = rem + len[idx];
        }

        return min(skip, take);
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        n = arr.size();
        // memo.assign(n, vector<int>(3, -1));
        // len.assign(n, -1);

        vector<int> besti(n, INT_MAX);

        int lft = 0;
        long long sum = 0;
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            while(sum > target) {
                sum -= arr[lft];
                lft++;
            }
 
            if(sum == target) {
                // len[lft] = i - lft + 1;
                int currLen = i - lft + 1;

                if(lft > 0 && besti[lft - 1] != INT_MAX) {
                    ans = min(ans, besti[lft - 1] + currLen);
                }

                besti[i] = min((i > 0 ? besti[i - 1] : INT_MAX), currLen);
            }
            else {
                besti[i] = (i > 0 ? besti[i - 1]: INT_MAX);
            }
        }    

        // return (helper(0, 2) == INT_MAX) ? -1 : helper(0, 2);

        return (ans == INT_MAX) ? -1 : ans;   
    }
};