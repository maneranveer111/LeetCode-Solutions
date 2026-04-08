class Solution {
public:
    bool judgeCircle(string s) {
        int lr = 0, ud = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'L') lr--;
            else if(s[i] == 'R') lr++;
            else if(s[i] == 'U') ud++;
            else ud--;
        }

        if(ud == 0 && lr == 0)
            return true;
        
        return false;
    }
};