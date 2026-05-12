class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int lft = 0, rht = tokens.size() - 1;
        int curr = 0, ans = 0;

        while(lft <= rht) {
            if(tokens[lft] <= power) {
                power -= tokens[lft];
                curr += 1;
                lft++;
            }
            else {
                if(curr >= 1) {
                    power += tokens[rht];
                    curr -= 1;
                }
                rht--;
            }
            

            ans = max(ans, curr);
        }

        return ans;
    } 
};