class Solution {
public:
    int findNthDigit(int n) {
        long long total = 0, lower = 0;
        int cnt = 1;
        long long multi = 1;

        while (total < n) {
            lower = total;
            total += (9 * multi * cnt);
            cnt++;
            multi *= 10;
        }

        cnt--;

        long long offset = n - lower;
        long long number = (multi / 10) + (offset - 1) / cnt;
        int digIdx = (offset - 1) % cnt;

        string s = to_string(number);
        return s[digIdx] - '0';
    }
};