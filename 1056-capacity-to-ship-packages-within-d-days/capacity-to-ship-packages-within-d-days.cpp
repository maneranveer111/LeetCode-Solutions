class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for(int i : weights) {
            high += i;
            low = max(low, i);
        }

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int day = 1, cap = 0;

            for(int i = 0; i < weights.size(); i++) {
                if(cap + weights[i] > mid) {
                    day++;
                    cap = 0;
                }
                cap += weights[i];
            }
            
            if(day <= days) {
                ans = mid;
                high = mid - 1;
            }            
            else 
                low = mid + 1;
        }

        return ans;
    }
};
