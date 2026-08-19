class Solution {
public:
    const int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> newArray;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                newArray.push_back(sum);
            }
        }   

        sort(newArray.begin(), newArray.end());

        int lft = left - 1, rht = right - 1;
        long long ans = 0;
        while(lft <= rht) {
            ans += newArray[lft] + newArray[rht];
            if(lft == rht)
                ans -= newArray[lft];
            ans %= MOD;
            lft++;
            rht--;
        }

        return ans;
    }
};