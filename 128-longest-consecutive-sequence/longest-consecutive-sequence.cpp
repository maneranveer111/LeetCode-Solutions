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
        
        set<int> store, curr;
        unordered_map<int, int> check;

        for(int i = 0; i < nums.size(); i++)
            store.insert(nums[i]);

        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int currLen = 0, maxLen = 0;
        for(int i : nums) {
            int x = i;
            if(!curr.count(x)) {
                currLen = 1;
                while(store.count(x + 1)) {
                    curr.insert(x);
                    if(check.count(x + 1)) {
                        currLen += check[x + 1];
                        break;
                    }

                    currLen++;
                    x += 1;
                }

                check[i] = currLen;
                maxLen = max(currLen, maxLen);
            }
        }

        return maxLen;
    }
};