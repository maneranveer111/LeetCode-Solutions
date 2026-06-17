class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> store(s.size());
       long long len = 0, i = 0;
        for(char ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                len++;
                store[i++] = len;
            }
            else if(ch == '*') {
                if(len > 0) len--;
                store[i++] = len;
            }
            else if(ch == '%') {
                store[i++] = len;
            }
            else if(ch == '#') {
                len *= 2;
                store[i++] = len;
            }
        } 
        if(k >= store[s.size()-1]) 
            return '.';

        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                if(k == store[i] - 1)
                    return  s[i];
            }
            else if(s[i] == '#') {
                long long half = store[i] / 2;
                if(k >= half)
                    k -= half;
            }
            else if(s[i] == '%') {
                k = store[i] - 1 - k;
            }
        }
        
        return '.';
    }
};