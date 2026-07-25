class Solution {
public:
    int maxProduct(int n) {
        int max1 = INT_MIN, max2 = INT_MIN;

        while(n) {
            int dig = n % 10;

            if(dig >= max1) {
                max2 = max1;
                max1 = dig;
            }
            else if(dig >= max2)
                max2 = dig;

            n /= 10;
        }   

        return max1 * max2;
    }
};