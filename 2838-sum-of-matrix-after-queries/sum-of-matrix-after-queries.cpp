class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        vector<int> row, col;

        for(int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0], val = queries[i][2], idx = queries[i][1];
            if(type == 0) {
                if(find(row.begin(), row.end(), idx) != row.end())
                    continue;
                row.push_back(idx);
                int cnt = col.size();
                ans += (val * n) - (cnt * val);
            }
            else if(type == 1) {
                if(find(col.begin(), col.end(), idx) != col.end())
                    continue;
                col.push_back(idx);
                int cnt = row.size();
                ans += (val * n) - (cnt * val);
            }
        }

        return ans;
    }
};