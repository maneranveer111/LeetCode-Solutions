class Solution {
public:
    string minWindow(string s, string t) {
        if (s == t) return s;
        if (t.size() > s.size()) return "";

        unordered_map<char, int> freq;
        for (char c : t)
            freq[c]++;

        unordered_map<char, int> curr;
        int cnt = 0;
        int j = 0;
        int minLen = INT_MAX;
        int l = -1;

        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (freq.count(c)) {
                curr[c]++;
                if (curr[c] == freq[c])
                    cnt++;
            }

            while (j <= i && cnt == (int)freq.size()) {
                if (i - j + 1 < minLen) {
                    minLen = i - j + 1;
                    l = j;
                }

                char lc = s[j];
                if (freq.count(lc)) {
                    curr[lc]--;
                    if (curr[lc] < freq[lc])
                        cnt--;
                }
                j++;
            }
        }

        return l == -1 ? "" : s.substr(l, minLen);
    }
};