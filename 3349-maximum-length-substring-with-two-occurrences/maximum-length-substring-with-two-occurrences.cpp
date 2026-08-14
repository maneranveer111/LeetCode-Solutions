class Solution {
public:
    int maximumLengthSubstring(string s) {
        int lft = 0;
        unordered_map<char, int> mp;
        int len = 0;

        for(int i = 0; i < s.size(); i++) {
            
            mp[s[i]]++;
            
            while(mp[s[i]] > 2) {
                mp[s[lft]]--;
                lft++;
            }

            len = max(len, i - lft + 1);
        }

        return len;
    }
};