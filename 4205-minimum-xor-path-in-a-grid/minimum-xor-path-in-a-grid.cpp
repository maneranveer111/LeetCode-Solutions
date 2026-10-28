class Solution {
public:
    int ans = INT_MAX;
    int m, n;

    // unordered_set<string> memo;
    vector<vector<vector<int>>> memo;

    void helper(int i, int j, int curr, vector<vector<int>>& grid) {
        if(i >= m || j >= n || i < 0 || j < 0)
            return;
            
        if(i == m - 1 && j == n - 1) {
            curr = curr ^ grid[i][j];
            ans = min(ans, curr);
            return;
        }

        // string key = to_string(i) + "#" + to_string(j) + "#" + to_string(curr);
        // if(memo.find(key) != memo.end())
        if(memo[i][j][curr])
            return;


        memo[i][j][curr] = 1;

        helper(i, j + 1, curr ^ grid[i][j], grid);
        helper(i + 1, j, curr ^ grid[i][j], grid);

        // memo.insert(key);
    }

    int minCost(vector<vector<int>>& grid) {
        // int m, n;
        this->m = grid.size(), this->n = grid[0].size();
        memo.assign(m, vector<vector<int>>(n, vector<int>(1024, 0)));
        helper(0, 0, 0, grid);

        return ans;
    }
};