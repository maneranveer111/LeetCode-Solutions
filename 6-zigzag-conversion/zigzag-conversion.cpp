class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<vector<char>> store(numRows);
        int row = 0, dir = 1;

        for (int i = 0; i < s.size(); i++) {
            store[row].push_back(s[i]);

            if (row == 0) dir = 1;
            if (row == numRows - 1) dir = -1;

            row += dir;
        }

        string ans = "";
        for (int i = 0; i < store.size(); i++)
            for (int j = 0; j < store[i].size(); j++)
                ans += store[i][j];

        return ans;
    }
};