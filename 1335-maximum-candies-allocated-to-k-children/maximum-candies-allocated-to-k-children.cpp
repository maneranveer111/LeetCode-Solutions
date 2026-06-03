class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        for(int i : candies)
            total += i;
        if(total < k)
            return 0;
        
        long long low = 1, high = *max_element(candies.begin(), candies.end());;
        long long ans = high;

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long part = 0;

            for(int i : candies) {
                if(mid != 0) part += i / mid;
            }

            if(part >= k) {
                ans = mid;
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }

        return ans;
    }
};
