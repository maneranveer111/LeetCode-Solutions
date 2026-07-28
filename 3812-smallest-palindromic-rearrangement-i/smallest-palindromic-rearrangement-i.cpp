class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for(char ch : s) 
            freq[ch - 'a']++;
        
        int len = s.size();
        string ans = "";
        char last = '#';

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 0) {
                string tmp(freq[i] / 2, i + 'a');
                ans += tmp;
            }
            else {
                if(freq[i] == 1)
                    last = i + 'a';
                else {
                    string tmp((freq[i] - 1) / 2, i + 'a');
                    ans += tmp;
                    last = i + 'a';
                }
            }
        }


        string lst = ans;
        reverse(lst.begin(), lst.end());

        if(last == '#')
            return ans + lst;
        ans.push_back(last);

        return ans + lst;
    }
};