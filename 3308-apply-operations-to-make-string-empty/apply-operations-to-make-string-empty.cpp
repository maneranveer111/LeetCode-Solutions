class Solution {
public:
    string lastNonEmptyString(string s) {
        string temp = s;
        int n = temp.size();
        unordered_map<char, int> mp;
        unordered_map<char, int> idx;

        for(int i = 0; i < n; i++) {
            idx[s[i]] = i;
            mp[s[i]]++;
        }
        int mxFreq = INT_MIN;
        for(auto [key, val] : mp) {
            mxFreq = max(mxFreq, val);
        }
        string ans = "";
        for(auto [key, val] : mp) {
            if(val == mxFreq)
                ans.push_back(key);
        }

        sort(ans.begin(), ans.end(), [&](char a, char b) {
            return idx[a] < idx[b];
        });

        
        return ans;
    }
};