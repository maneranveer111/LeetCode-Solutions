class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int cntEve = 0;
        int cntOdd = 0;

        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2 == 0) cntEve++;
            else cntOdd++;
        }

        if(cntEve == n || cntEve + cntOdd == n || cntOdd == n) return true;

        return false;
     }
};