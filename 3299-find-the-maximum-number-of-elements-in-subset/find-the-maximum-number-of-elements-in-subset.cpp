class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        
        int ans = (mp.count(1)) ? (mp[1] -= (mp[1] % 2 == 0) ? 1 : 0) : 0; 

        for(auto& [a, cnt] : mp) {
            if(a == 1)
                continue;
            int len = 0;
            long long x = a;

            while(mp.count((int)x) && mp[(int)x] >= 2) {
                if(x > 46340) break; 
                x = x * x;
                len += 2;
            }

            if(mp.count((int)x) && mp[(int)x] >= 1)
                len += 1;
            else
                len = max(len - 1, 1);

            ans = max(len, ans);
        }

        return ans;
    }
};