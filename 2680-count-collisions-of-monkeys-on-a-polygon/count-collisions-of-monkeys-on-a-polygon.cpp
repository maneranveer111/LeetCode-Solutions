class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return res;
    }

    int monkeyMove(int n) {
        return (power(2, n) - 2 + MOD) % MOD;
    }
};