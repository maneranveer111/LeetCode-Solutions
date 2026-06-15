class Solution {
public:
    long long helper(vector<int>& nums) {
        long long curr = nums[0];
        long long ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            curr = max((long long)nums[i], curr + nums[i]);
            ans = max(ans, curr);
        }

        return ans;
    }

    long long solveRemainingCase(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MIN;

        multiset<int> outside(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            long long windowSum = 0;
            multiset<int> inside;
            outside = multiset<int>(nums.begin(), nums.end());

            for(int j = i; j < n; j++) {
                outside.erase(outside.find(nums[j]));
                inside.insert(nums[j]);
                windowSum += nums[j];
                long long bestSum = windowSum;
                multiset<int> tempInside = inside;
                multiset<int> tempOutside = outside;

                for(int swap = 0; swap < k; swap++) {
                    if(tempInside.empty() || tempOutside.empty())
                        break;
                    
                    int worstInside = *tempInside.begin();
                    int bestOutside = *tempOutside.rbegin();

                    if(worstInside < 0 && bestOutside > 0) {
                        bestSum += (bestOutside - worstInside);
                        tempInside.erase(tempInside.begin());
                        tempOutside.erase(prev(tempOutside.end()));
                    }
                    else 
                        break;
                }
                    ans = max(ans, bestSum);
            }
        }

        return ans;
    }

    long long maxSum(vector<int>& nums, int k) {
        if(k == 0)
            return helper(nums);

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        long long total = 0;
        long long neg = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0)
                total += nums[i];
            else
                neg++;
        }

        if(mx < 0)                
            return mx;

        if(mn >= 0 || neg <= k)  
            return total;

        return solveRemainingCase(nums, k);
    }
};

