class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> idx(mat.size());
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&mat](int a, int b) {
            int cnta = 0, cntb = 0;
            for (int i = 0; i < (int)mat[0].size(); i++) {
                if (mat[a][i] == 1) cnta++;
                if (mat[b][i] == 1) cntb++;
            }
            if (cnta != cntb) return cnta < cntb;
            return a < b;  
        });

        return {idx.begin(), idx.begin() + k};
    }
};