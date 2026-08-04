class Solution {
public:
    unordered_map<int, bool> memo;
    int n;
    
    bool helper(int usedMask, int desiredTotal) {
        if(desiredTotal <= 0)
            return true;
        
        if(memo.count(usedMask))
            return memo[usedMask];

        for(int i = 1; i <= n; i++) {
            int bit = 1 << (i - 1);
            if(usedMask & bit)
                continue;
            
            if(i >= desiredTotal || !helper(usedMask | bit, desiredTotal - i))
                return memo[usedMask] = true;
        }

        return memo[usedMask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        n = maxChoosableInteger;
        int sum = n * (n + 1) / 2;

        if(sum < desiredTotal)
            return false;
        if(desiredTotal <= 0)
            return true;
        
        memo.clear();
        
        return helper(0, desiredTotal); 
    }
};