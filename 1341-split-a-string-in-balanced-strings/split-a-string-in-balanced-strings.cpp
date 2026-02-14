class Solution {
public:
    int balancedStringSplit(string s) {
        int cntR = 0, cntL = 0;
        int total = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'R') cntR++;
            else cntL++;
            if(cntR == cntL && cntR != 0) {
                total++;
                cntR = 0;
                cntL = 0;
            }
        }  

        return total; 
    }
};