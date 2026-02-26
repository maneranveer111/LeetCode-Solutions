class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    bool canMeasureWater(int x, int y, int target) {
       if(x + y >= target && target % gcd(x, y) == 0) return true;
       return false; 
    }
};