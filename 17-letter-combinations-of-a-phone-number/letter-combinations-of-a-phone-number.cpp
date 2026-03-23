class Solution {
public:
    vector<string> result;
    unordered_map<char, string> phone_map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void helper(int idx, string current, string& digits) {
        if(idx == digits.size()) {
            result.push_back(current);
            return;
        }

        for(char c : phone_map[digits[idx]]) {
            helper(idx + 1, current + c, digits);
        }

    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        helper(0, "", digits);
        return result;
    }
};