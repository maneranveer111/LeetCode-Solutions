class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int left_max = 0, right_max = 0;

        for (int i = n - 1; i > 0; i--) {
            if (colors[i] != colors[0]) {
                left_max = i;
                break;
            }
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                right_max = (n - 1) - i;
                break;
            }
        }

        return max(left_max, right_max);
    }
};