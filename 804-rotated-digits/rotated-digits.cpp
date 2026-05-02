class Solution {
public:
    bool isGood(int x) {
        bool hasDifferent = false;  
        
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            
            if (digit == 3 || digit == 4 || digit == 7)
                return false;

            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                hasDifferent = true;
            
        }
        
        return hasDifferent; 
    }

    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i))
                count++;
        }
        return count;
    }
};