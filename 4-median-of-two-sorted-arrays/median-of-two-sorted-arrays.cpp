class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int m = nums1.size();
        int n = nums2.size();
        int lo = 0, hi = m, half = (m + n + 1) / 2;

        while(lo <= hi) {
            int p1 = lo + (hi - lo) / 2;
            int p2 = half - p1;

            int maxLeft1 = (p1 == 0) ? INT_MIN : nums1[p1 - 1];
            int minRight1 = (p1 == m) ? INT_MAX : nums1[p1];

            int maxLeft2 = (p2 == 0) ? INT_MIN : nums2[p2 - 1];
            int minRight2 = (p2 == n) ? INT_MAX : nums2[p2];

            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if((m + n) % 2 == 1)
                    return max(maxLeft1, maxLeft2);
                else 
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
            else if(maxLeft1 > minRight2)
                hi = p1 - 1;
            else 
                lo = p1 + 1;

        }

        return 0.0;
    }
};
