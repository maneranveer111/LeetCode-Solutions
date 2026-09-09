class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        long long commas = 1;

        while(start <= n) {
            long long end = start * 1000 - 1;

            long long cnt = min(n, end) - start + 1;
            if(cnt > 0) ans += cnt * commas;
            commas++;
            start *= 1000;
        }

        return ans;
    }
};