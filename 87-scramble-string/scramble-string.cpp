class Solution {
public:
    unordered_map<string, bool> memo;

    bool isAnagram(int i1, int i2, int len, string &s1, string &s2) {
        unordered_map<char, int> mp;
        for (int k = 0; k < len; k++) {
            mp[s1[i1 + k]]++;
            mp[s2[i2 + k]]--;
        }
        for (auto [key, val] : mp)
            if (val != 0) return false;
        return true;
    }

    bool helper(int i1, int i2, int len, string s1, string s2) {
        if(s1.compare(i1, len, s2, i2, len) == 0)
            return true;
        
        if(!isAnagram(i1, i2, len, s1, s2))
            return false;
        
        string key = to_string(i1) + "#" + to_string(i2) + "#" + to_string(len);

        if(memo.count(key))
            return memo[key];
        
        bool flag = false;
        for(int k = 1; k < len && !flag; k++) {
            if(helper(i1, i2, k, s1, s2) && helper(i1 + k, i2 + k, len - k, s1, s2))
                flag = true;

            if(helper(i1, i2 + len - k, k, s1, s2) && helper(i1 + k, i2, len - k, s1, s2))
                flag = true;
        }

        return memo[key] = flag;
    }

    bool isScramble(string s1, string s2) {
        return helper(0, 0, s1.size(), s1, s2);
    }
};