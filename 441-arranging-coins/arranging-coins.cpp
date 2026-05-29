class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        int lft = 1, rht = n;
        if(n == 1)
            return 1;
        while(lft <= rht) {
            long long mid = lft + (rht - lft) / 2;

            if((long long)(mid * (mid + 1)) / 2 <= n) {
                lft = mid + 1;
                ans = lft;
            }
            else 
                rht = mid - 1;
        }

        return ans - 1;

    }
};