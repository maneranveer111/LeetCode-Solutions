class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();

        for(int x : arr)
            mp[x]++;

        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        for (int x : arr) {
            if (mp[x] == 0) continue;       
            mp[x]--;                         
            if (mp[2 * x] <= 0) return false; 
            mp[2 * x]--;
        }

        return true;
    }
};
