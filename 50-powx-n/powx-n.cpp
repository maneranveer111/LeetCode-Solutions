class Solution {
public:
    double helper(double x, long long n) {
        if(n == 0)
            return 1.0;
        if(n % 2 == 0) {
            double half = helper(x, n / 2);
            return half * half;
        }

        return x * helper(x, n - 1);
    }

    double myPow(double x, int n) { 
        if(n < 0)
            return 1.0 / helper(x, -(long long)n);
        else 
            return helper(x, n);
    }
};
