class Solution {
public:
    vector<vector<int>> memo;

    int helper(int idx, int flag, vector<int>& arr) {
        if(idx == arr.size() - 1)
            return 1;

        if(memo[idx][flag + 1] != -1)
            return memo[idx][flag + 1];

        int go1 = INT_MIN, go2 = INT_MIN, skip = INT_MIN, skip1 = INT_MIN;

        if((flag == 1 || flag == -1)) {
            if(idx % 2 == 0 && arr[idx] < arr[idx + 1]) {
                go1 = 1 + helper(idx + 1, 1, arr);
            }
            else if(idx % 2 && arr[idx] > arr[idx + 1]) {
                go1 = 1 + helper(idx + 1, 1, arr);
            }
            else 
                go1 = 1;
        }

        if(flag == 0 || flag == -1) {
           if(idx % 2 == 0 && arr[idx] > arr[idx + 1]) {
                go2 = 1 + helper(idx + 1, 0, arr);
            }
            else if(idx % 2 && arr[idx] < arr[idx + 1]) {
                go2 = 1 + helper(idx + 1, 0, arr);
            } 
            else 
                go2 = 1;
        }   

        if(flag == -1)
            skip = helper(idx + 1, -1, arr);

        int ans = std::max({go1, go2, skip});
        return memo[idx][flag + 1] = ans;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        memo.assign(n, vector<int>(3, -1));
        int ans = helper(0, -1, arr);
        return ans;
    }
};