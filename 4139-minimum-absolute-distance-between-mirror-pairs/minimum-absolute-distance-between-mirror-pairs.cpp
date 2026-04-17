class Solution {
public:
    int reverseNum(int x) {
        string s = to_string(x);
        reverse(s.begin(), s.end());

        int i = 0;
        while (i < s.size() - 1 && s[i] == '0') i++;

        return stoi(s.substr(i));
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int rev = reverseNum(nums[i]);

            if (mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }

            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};