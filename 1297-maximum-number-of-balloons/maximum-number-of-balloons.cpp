class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        mp['b'] = 0;
        mp['n'] = 0;
        mp['a'] = 0;
        mp['o'] = 0;
        mp['l'] = 0;

        for(char ch : text) {
            if(mp.find(ch) != mp.end())
                mp[ch]++;
        }   

        int ans = INT_MAX;
        for (auto it : mp) {
            if (it.first == 'l' || it.first == 'o')
                ans = min(ans, it.second / 2);
            else
                ans = min(ans, it.second);
        }

        return ans;
    }
};