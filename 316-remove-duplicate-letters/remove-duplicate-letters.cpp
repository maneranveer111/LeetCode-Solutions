class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> freq(26);
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        vector<bool> isPresent(26, false);
        string ans = "";

        for(char ch : s) {
            freq[ch - 'a']--;

            if(isPresent[ch - 'a']) continue;

            while(!ans.empty() && ans.back() > ch && freq[ans.back() - 'a'] > 0) {
                isPresent[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += ch;
            isPresent[ch - 'a'] = true;
        }

        return ans;
    }
};