class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        vector<int> left(n), right(n);
        stack<int> st;

        for(int i = 0; i < n ; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            
            left[i] = (st.empty()) ? 0 : st.top() + 1;

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            right[i] = (st.empty()) ? n : st.top();

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            long long rangesm = prefix[right[i]] - prefix[left[i]];
            long long product = nums[i] * rangesm;

            ans = max(ans, product);
        }

        return (int) (ans % MOD);
    }
};