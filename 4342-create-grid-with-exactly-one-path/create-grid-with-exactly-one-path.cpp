class Solution {
public:
    bool helper(vector<vector<int>>& ans, int i, int j, int m, int n) {
        ans[i][j] = 1;
        if(i == m - 1 && j == n - 1)
            return true;
        if(i + 1 < m) {
            if(helper(ans, i + 1, j, m, n))
                return true;
        }
        if(j + 1 < n)
            if(helper(ans, i, j + 1, m, n))
                return true;
        ans[i][j] = -1;
        return false;
    }
    vector<string> createGrid(int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        helper(ans, 0, 0, m, n);
        vector<string> result(m);
        for(int i = 0; i < m; i++) {
            string temp = "";
            for(int j = 0; j < n; j++) {
                if(ans[i][j] == 1)
                    temp.push_back('.');
                else 
                    temp.push_back('#');
            }

            result[i] = temp;
        }

        return result;
    }
};