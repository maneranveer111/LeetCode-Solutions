class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;

        for (i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            }
            else if (c == '+' || c == '-') {

                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                if (seenDot || seenE)
                    return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (seenE || !seenDigit)
                    return false;
                seenE = true;
                seenDigit = false;
            }
            else {

                return false;
            }
        }

        return seenDigit; 
    }
};