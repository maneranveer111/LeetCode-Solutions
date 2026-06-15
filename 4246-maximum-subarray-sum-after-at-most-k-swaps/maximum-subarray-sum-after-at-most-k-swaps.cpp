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
        
        for(int left = 0; left < n; left++) {
            multiset<int> inside;
            long long window_sum = 0;

            outside = multiset<int>(nums.begin(), nums.end());

            for(int right = left; right < n; right++) {

                outside.erase(outside.find(nums[right]));
                inside.insert(nums[right]);
                window_sum += nums[right];

                long long effective_sum = window_sum;
                multiset<int> temp_inside = inside;
                multiset<int> temp_outside = outside;

                for(int swap = 0; swap < k; swap++) {
                    if(temp_inside.empty() || temp_outside.empty()) break;

                    int worst_inside = *temp_inside.begin();   
                    int best_outside = *temp_outside.rbegin(); 

                    if(worst_inside < 0 && best_outside > 0) {
                        effective_sum += (best_outside - worst_inside);
                        temp_inside.erase(temp_inside.begin());
                        temp_outside.erase(prev(temp_outside.end()));
                    } else {
                        break;
                    }
                }

                ans = max(ans, effective_sum);
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

