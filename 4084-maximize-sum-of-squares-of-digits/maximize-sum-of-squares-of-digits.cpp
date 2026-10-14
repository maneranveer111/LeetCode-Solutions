class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num || sum < 1) return "";
        string res;
        res.reserve(num);
        int rem = sum;
        for (int i = 0; i < num; i++) {
            int d = rem < 9 ? rem : 9;
            res.push_back('0' + d);
            rem -= d;
        }
        return res;
    }
};