class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> store(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            store[i] = to_string(nums[i]);
        }

        sort(store.begin(), store.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        string ans = "";

        for(int i = 0; i < nums.size(); i++) {
            ans += store[i];
        }

        return (ans[0] == '0') ? "0" : ans;
    }
};