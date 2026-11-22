class Solution {
public:
    bool checkString(string s) {
        int first = -1, last = -1;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a')
                last = i;
            else if(first == -1)
                first = i;
        }

        if(first == -1 || last == -1)
            return true;
        
        if(last + 1 == first)
            return true;
        
        return false;
    }
};