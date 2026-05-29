class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;

        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(num % mid == 0 && num / mid == mid)
                return true;
            else if(num / mid < mid)
                high = mid - 1;
            else 
                low = mid + 1;
        }

        return false;
    }
};