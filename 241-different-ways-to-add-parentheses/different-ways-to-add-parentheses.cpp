class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string s) {
        if (memo.count(s)) return memo[s];
        vector<int> result;

        bool hasOperator = false;
        for (char c : s) {
            if (c == '+' || c == '-' || c == '*') {
                hasOperator = true;
                break;
            }
        }
        if (!hasOperator) return memo[s] = {stoi(s)};  

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left  = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i + 1));

                for (int l : left)
                    for (int r : right) {
                        if (ch == '+') result.push_back(l + r);
                        if (ch == '-') result.push_back(l - r); 
                        if (ch == '*') result.push_back(l * r);  
                    }
            }                                                     
        }

        memo[s] = result;
        return result;
    }
};