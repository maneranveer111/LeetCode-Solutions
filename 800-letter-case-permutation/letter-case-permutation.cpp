class Solution {
public:
    vector<string> ans;

    void helper(string s, int idx) {
        if (idx == (int)s.size()) {
            ans.push_back(s);
            return;
        }

        char c = s[idx];

        if (c >= 'a' && c <= 'z') {
            helper(s, idx + 1);

            s[idx] = std::toupper((unsigned char)c);
            helper(s, idx + 1);
        }
        else if (c >= 'A' && c <= 'Z') {
            helper(s, idx + 1);

            s[idx] = std::tolower((unsigned char)c);
            helper(s, idx + 1);
        }
        else {
            helper(s, idx + 1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return ans;
    }
};