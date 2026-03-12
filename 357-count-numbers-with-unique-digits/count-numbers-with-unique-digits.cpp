class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10;
        int temp = 9, temp2 = 9;

        for(int i = 2; i <= n && temp2 > 0; i++) {
            temp *= temp2;
            ans += temp;
            temp2--;
        }

        return ans;
    }
};