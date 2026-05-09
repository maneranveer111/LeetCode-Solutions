class Solution {
public:

    void reverseArray(vector<int>& arr, int l, int h) {
        while (l < h) {
            swap(arr[l], arr[h]);
            l++;
            h--;
        }
    }

    // Right rotation
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();

        k %= n;

        reverseArray(arr, 0, n - 1);
        reverseArray(arr, 0, k - 1);
        reverseArray(arr, k, n - 1);
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int stR = 0, enR = grid.size() - 1;
        int stC = 0, enC = grid[0].size() - 1;

        while (stR < enR && stC < enC) {

            vector<int> temp;

            for (int i = stC; i <= enC; i++)
                temp.push_back(grid[stR][i]);

            for (int i = stR + 1; i <= enR; i++)
                temp.push_back(grid[i][enC]);

            for (int i = enC - 1; i >= stC; i--)
                temp.push_back(grid[enR][i]);

            for (int i = enR - 1; i > stR; i--)
                temp.push_back(grid[i][stC]);

            int len = temp.size();

            int rot = len - (k % len);

            rotate(temp, rot);

            int idx = 0;

            for (int i = stC; i <= enC; i++)
                grid[stR][i] = temp[idx++];

            for (int i = stR + 1; i <= enR; i++)
                grid[i][enC] = temp[idx++];

            for (int i = enC - 1; i >= stC; i--)
                grid[enR][i] = temp[idx++];

            for (int i = enR - 1; i > stR; i--)
                grid[i][stC] = temp[idx++];

            stR++;
            enR--;
            stC++;
            enC--;
        }

        return grid;
    }
};