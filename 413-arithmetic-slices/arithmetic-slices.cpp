class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        set<pair<int, int>> st;

        for(int i = 0; i < nums.size(); i++) {
            int diff = 0;
            if(i + 1 < nums.size())
                diff = nums[i + 1] - nums[i];

            int j = i + 1;
            while(j < nums.size() && nums[j] - nums[j - 1] == diff) {
                if(j - i + 1 >= 3) {
                    st.insert({i, j});
                }
                j++;
            }
        }

        return st.size();
    }
};