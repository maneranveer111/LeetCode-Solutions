class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;
        int diff0 = 0;

        for (int i = 0; i < n; i++) {
            char exp = (i % 2 == 0) ? '0' : '1';
            if (s[i] != exp) diff0++;
        }

        int ans = min(diff0, n - diff0);  

        for (int i = n; i < 2 * n; i++) {
            char exp = (i % 2 == 0) ? '0' : '1';
            if (ss[i] != exp) diff0++;

            int lidx = i - n;
            char lexp = (lidx % 2 == 0) ? '0' : '1';
            if (ss[lidx] != lexp) diff0--;  
            ans = min({ans, diff0, n - diff0});
        }

        return ans;
    }
};