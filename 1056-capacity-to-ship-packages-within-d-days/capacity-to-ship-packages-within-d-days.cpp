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
            int i = 0, cap = 0, day = 0;

            while(i < weights.size()) {
                while(i < weights.size() && cap + weights[i] <= mid) {
                    cap += weights[i];
                    i++;
                }
                // i++;/
                day++;
                cap = 0;
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
