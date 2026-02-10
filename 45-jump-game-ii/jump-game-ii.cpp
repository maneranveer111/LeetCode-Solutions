class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lft = 0, rht = 0; 
        int jump = 0;

        while(rht < n - 1) {
            int far = INT_MIN;
            for(int i = lft; i <= rht; i++) {
                far = max(far, i + nums[i]);
            }

            lft = rht + 1;
            rht = far;
            jump++;
        }

        return jump;
    }
};