class Solution {
public:
    int helper(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int row = n - 1, col = 0;
        int cnt = 0;

        while(row >= 0 && col < n) {
            if(matrix[row][col] <= mid) {
                cnt += row + 1;
                col++;
            }
            else 
                row--;
        }

        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1]; 

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int cnt = helper(matrix, mid);

            if(cnt < k) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        } 

        return lo;
    }
};