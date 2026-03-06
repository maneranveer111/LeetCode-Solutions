class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> minLeft(n), minRht(n);
        vector<int> maxLeft(n), maxRht(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            minLeft[i] = st.empty() ? -1 : st.top();  
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();  
            minRht[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            maxLeft[i] = st.empty() ? -1 : st.top(); 
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();  
            maxRht[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            long long leftMin = i - minLeft[i];
            long long rhtMin  = minRht[i] - i;
            long long leftMax = i - maxLeft[i];
            long long rhtMax  = maxRht[i] - i;

            ans -= (long long)nums[i] * leftMin * rhtMin;  
            ans += (long long)nums[i] * leftMax * rhtMax;  
        }

        return ans;
    }
};