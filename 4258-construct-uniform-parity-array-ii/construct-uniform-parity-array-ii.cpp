class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minEle = INT_MAX;
        int cntEve = 0;
        for(int i = 0; i < n; i++){ 
            minEle = min(minEle, nums1[i]);
            if(nums1[i] % 2 == 0) cntEve++;
        }

        if(minEle % 2 != 0) return true;
        if(cntEve < n) return false;

        return true;
    }
};