class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int tmp = 26 - (s[i] - 'a'); 
            ans += tmp * (i + 1);      
        }
        return ans;
    }
};