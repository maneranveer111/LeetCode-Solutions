class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int k_max = INT_MIN;
        vector<int> min_sofar(n);
        int mnm = INT_MAX;
    
        for(int i = 0; i < n; i++) {
            min_sofar[i] = mnm;
            mnm = min(mnm, nums[i]);
        }

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && st.top() < nums[i]) {
                k_max = max(st.top(), k_max);
                st.pop();
            }

            if(min_sofar[i] < k_max && k_max < nums[i]) return true;
            st.push(nums[i]);
        }

        return false;
    }
};