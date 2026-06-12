class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        for(int j = n; j > 1; j--) {
            int maxIdx = max_element(arr.begin(), arr.begin() + j) - arr.begin();

            if(maxIdx == j - 1)
                continue;
            
            if (maxIdx != 0) {
                ans.push_back(maxIdx + 1);
                reverse(arr.begin(), arr.begin() + maxIdx + 1);
            }

            ans.push_back(j);
            reverse(arr.begin(), arr.begin() + j);

        }

        return ans;
    }
};