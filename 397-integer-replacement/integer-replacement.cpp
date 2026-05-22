class Solution {
public:
    int helper(long long n) {
        if(n == 1)
            return 0;
        if(n < 1)
            return 1e8;
        
        long long eve = 1e8, odd1 = 1e8, odd2 = 1e8;

        if(n % 2 == 0)
            eve = 1 + helper(n / 2);
        else {
            odd1 = 1 + helper(n + 1);
            odd2 = 1 + helper(n - 1);
        }

        return (n % 2 == 0) ? (int)eve : min((int)odd1, (int)odd2);
    }

    int integerReplacement(int n) {
        return helper(n);
    }
};