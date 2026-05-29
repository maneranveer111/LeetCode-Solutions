class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        int lft = 0, rht = x / 2;
        int ans = 0;

        while(lft <= rht) {
            long long mid = lft + (rht - lft) / 2;

            if(mid * mid == x)
                return mid;
            else if(mid * mid < x) {
                ans = mid;
                lft = mid + 1;
            }
            else 
                rht = mid - 1;
        }

        return ans;
    }
};