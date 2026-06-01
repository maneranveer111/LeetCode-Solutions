class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1)
            return 1;
        long long diff = 4;
        long long ans = 1;

        for(long long i = 2; i <= n; i++) {
            ans += diff;
            diff += 4;
        } 

        return ans;
    }
};