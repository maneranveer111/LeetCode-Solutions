class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long hr = 0;
            for(int pile : piles) {
                hr += (pile + mid - 1) / mid; 
            }

            if(hr <= h) {
                high = mid - 1;
                ans = mid;
            }
            else 
                low = mid + 1;
        }

        return ans;
    }
};