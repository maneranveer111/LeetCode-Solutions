class Solution {
public:
    

    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
    
    // prefix_max[i] = max(nums[0..i])
    vector<int> prefix_max(n), suffix_min(n);
    
    prefix_max[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefix_max[i] = max(prefix_max[i-1], nums[i]);
    
    suffix_min[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--)
        suffix_min[i] = min(suffix_min[i+1], nums[i]);
    
    vector<int> ans(n);
    int comp_start = 0;
    
    for (int i = 0; i < n; i++) {
        // Cut exists AFTER i if prefix_max[i] <= suffix_min[i+1]
        // i.e., current component ends at i
        bool is_cut = (i == n-1) || (prefix_max[i] <= suffix_min[i+1]);
        
        if (is_cut) {
            int comp_max = prefix_max[i]; // max of current component
            for (int j = comp_start; j <= i; j++)
                ans[j] = comp_max;
            comp_start = i + 1;
        }
    }
    
    return ans;

       
    }
};