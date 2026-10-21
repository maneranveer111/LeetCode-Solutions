class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string sorted = s;
        sort(sorted.begin(), sorted.end());

        if (s == sorted)
            return 0;

        if (n == 2)
            return -1;

        if (s[0] == sorted[0] || s.back() == sorted.back())
            return 1;
            
        if (s[0] == sorted[n - 1] && sorted[n - 1] > sorted[n - 2] &&
            s[n - 1] == sorted[0] && sorted[0] < sorted[1])
            return 3;

        return 2;
    }
};