class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                if(find(s.begin() + i, s.end(), '1') != s.end()) {
                    return false;
                } 
                return true;
            }
        }

        return true;
    }
};