class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long high = *max_element(ranks.begin(), ranks.end());
        high = high * cars * cars;
        
        long long low = 1;
        long long ans = high;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long mxCars = 0;

            for(int i = 0; i < ranks.size(); i++) {
                mxCars += (long long)sqrt((double)mid / ranks[i]); 
            }

            if(mxCars >= cars) {
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }

        return ans;
    }
};