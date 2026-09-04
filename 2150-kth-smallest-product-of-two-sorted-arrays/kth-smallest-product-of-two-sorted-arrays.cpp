class Solution {
public:
    
    long long countLE(long long num, long long mid, vector<int>& nums2) {
        long long n2 = nums2.size();
        if(num == 0) {
            return mid >= 0 ? n2 : 0;
        }
        else if(num > 0) {
            long long lo = 0, hi = n2 - 1, pos = -1;

            while(lo <= hi) {
                long long m = (lo + hi) / 2;

                if((long long) num * nums2[m] <= mid) {
                    pos = m;
                    lo = m + 1;
                }
                else
                    hi = m - 1;
            }

            return pos + 1;
        }
        else {
            long long lo = 0, hi = n2 - 1, pos = n2;

            while(lo <= hi) {
                long long m = (lo + hi) / 2;

                if((long long) num * nums2[m] <= mid) {
                    hi = m - 1;
                    pos = m;
                }
                else
                    lo = m + 1;
            }

            return n2 - pos;
        }
    }

    bool isValid(long long mid, long long k, vector<int>& nums1, vector<int>& nums2) {
        long long cnt = 0;

        for(int num : nums1) {
            cnt += countLE(num, mid, nums2);

            if(cnt >= k)
                return true;
        }

        return (cnt >= k);
    } 

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();

        long long p1 = (long long) nums1[0] * nums2[0];
        long long p2 = (long long) nums1[0] * nums2[n2 - 1];
        long long p3 = (long long) nums1[n1 - 1] * nums2[0];
        long long p4 = (long long) nums1[n1 - 1] * nums2[n2 - 1];

        long long lo = min({p1, p2, p3, p4});
        long long hi = max({p1, p2, p3, p4});

        long long ans = hi;

        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if(isValid(mid, k, nums1, nums2)) {
                ans = mid;
                hi = mid - 1;
            }
            else 
                lo = mid + 1;
        }

        return ans;
    }
};