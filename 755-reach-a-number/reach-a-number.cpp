class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long k = 0, s = 0;
        while (true) {
            k++;
            s += k;
            if (s >= target && (s - target) % 2 == 0)
                return k;
        }
    }
};