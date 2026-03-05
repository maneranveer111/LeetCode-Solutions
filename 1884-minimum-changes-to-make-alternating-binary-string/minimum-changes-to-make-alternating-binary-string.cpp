class Solution {
public:
    int minOperations(string s) {
        int cnt10 = 0;
        int cnt01 = 0;

        for(int i = 0; i < s.size(); i++) {
            if(i % 2 == 0) {
                if(s[i] == '1') cnt01++;
                else cnt10++;
            }
            else {
                if(s[i] == '1') cnt10++;
                else cnt01++;
            }
        }

        int ans = min(cnt01, cnt10);

        return ans;
    }
};