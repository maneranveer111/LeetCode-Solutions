class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> ans;
        bool upward = true;
        
        int i = 0, j = 0;

        while(ans.size() < m * n) {

            ans.push_back(mat[i][j]);

            if(upward) {
                i--; 
                j++;
            } else {
                i++; 
                j--;
            }

            if(i < 0 && j < m) {           
                i = 0;
                upward = false;
            }
            else if(j >= m) {              
                j = m - 1;
                i += 2;
                upward = false;
            }
            else if(j < 0 && i < n) {      
                j = 0;
                upward = true;
            }
            else if(i >= n) {              
                i = n - 1;
                j += 2;
                upward = true;
            }
        }

        return ans;
    }
};
