class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
            int ans = INT_MAX;
            
        while(low <= high){
            int mid = low + (high - low)/2;
            ans = min(ans, arr[mid]);

            if(arr[mid] > arr[high] ) low = mid + 1;
            else high = mid - 1;
        }

        return ans;
    }
};