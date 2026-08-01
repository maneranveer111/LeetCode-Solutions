class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int maxLength = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++){
            int lft = i, rht = i;
            while(lft >= 0 && rht < s.size() && s[lft] == s[rht]){
                int len = rht - lft + 1;
                if(len > maxLength){
                    start = lft;
                    maxLength = len;
                }
                lft--;
                rht++;
            }

            

            lft = i; rht = i + 1;

            while(lft >= 0 && rht < s.size() && s[lft] == s[rht]){
                int len = rht - lft + 1;
                if(len > maxLength){
                    start = lft;
                    maxLength = len;
                }
                lft--;
                rht++;
            }

        }

        return s.substr(start, maxLength);
    }
};