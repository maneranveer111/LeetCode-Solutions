class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size();
        int idx = -1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            // if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            //     idx = mid;
            //     return mid;
            // }
            if(arr[mid] < arr[mid + 1]) low = mid + 1;
            else high = mid;
        }

        return low;
    }
};