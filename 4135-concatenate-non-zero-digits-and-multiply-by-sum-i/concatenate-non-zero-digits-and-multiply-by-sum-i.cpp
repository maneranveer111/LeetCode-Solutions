class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long nm = 0, sm = 0;

        for (char ch : s) {
            if (ch == '0')
                continue;
            nm = nm * 10 + (int)(ch - '0');
            sm += (int)(ch - '0');            
        }

        return nm * sm;
    }
};