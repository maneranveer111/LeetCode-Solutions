class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int i = 0, length = 1, maxlength = 1;
        // if(nums.empty())return 0;
        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i]  == nums[i - 1]){
        //        continue;
        //     }
        //     else if(nums[i] == nums[i - 1] + 1){
        //         length++;
        //         maxlength = max(length, maxlength);
        //     }
        //     else{
        //         length = 1;
        //     }
        
        // }
        // return maxlength;
        
        unordered_set<int> mp(nums.begin(), nums.end());
        int maxLen = 0;

        for(int x : mp) {

            if(!mp.count(x - 1)) {
                int currLen = 1;
                int curr = x;

                while(mp.count(curr + 1)) {
                    currLen++;
                    curr++;
                }

                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};