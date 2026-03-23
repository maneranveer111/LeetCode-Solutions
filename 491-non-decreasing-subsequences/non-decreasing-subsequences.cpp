class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    
    void helper(vector<int>& nums, vector<int>& curr, int idx){
        if(curr.size() >= 2){
            if(st.find(curr) == st.end()){
                ans.push_back(curr);
                st.insert(curr);
            }
        }
        
        for(int i = idx; i < nums.size(); i++) {
            if(curr.size() == 0 || nums[i] >= curr[curr.size() - 1]) {
                curr.push_back(nums[i]);
                helper(nums, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        helper(nums, curr, 0);
        return ans;  
    }
};