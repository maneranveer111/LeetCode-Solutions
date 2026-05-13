class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans = 1.0;
        return (n == 1) ? ans / 1 : ans / 2 ;
    }
};