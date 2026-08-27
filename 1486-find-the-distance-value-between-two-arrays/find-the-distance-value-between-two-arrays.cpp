class Solution {
public:
    bool isValid(int a, int d, vector<int>& arr2) {
        for (int x : arr2) {
            if (abs(a - x) <= d)
                return false;
        }
        return true;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for (int a : arr1) {
            if (isValid(a, d, arr2))
                count++;
        }
        return count;
    }
};