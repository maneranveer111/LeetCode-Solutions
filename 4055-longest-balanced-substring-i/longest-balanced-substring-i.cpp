class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mp;
            int maxFreq = 0;
            for(int j = i; j < s.size(); j++) {
                mp[s[j]]++;
                maxFreq = max(mp[s[j]], maxFreq);
                if(maxFreq * mp.size() == j - i + 1) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};