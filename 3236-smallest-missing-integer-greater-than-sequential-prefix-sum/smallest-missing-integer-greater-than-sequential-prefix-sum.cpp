class Solution {
public:
    unordered_set<int> st;

    int helper(vector<int>& nums) {
        long long sum = nums[0];
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            i++;
        }
        return sum;
    }

    int missingInteger(vector<int>& nums) {
        int help = helper(nums);
        // cout << help << endl;
        st.clear();
        for(int x : nums)
            st.insert(x);

        while(st.count(help)) {
            help++;
        }

        return help;
    }
};

