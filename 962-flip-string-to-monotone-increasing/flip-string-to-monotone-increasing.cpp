class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cntOne = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1')
                cntOne++;
            else 
                ans = min(ans + 1, cntOne);
        }

        return ans;
    }
};