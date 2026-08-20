class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;

        for(int ans : answers) 
            mp[ans]++;

        int ans = 0;

        for(auto [x, y] : mp) {
            int groups = (y + x) / (x + 1); 
            ans += groups * (x + 1);
        }

        return ans;
    }
};