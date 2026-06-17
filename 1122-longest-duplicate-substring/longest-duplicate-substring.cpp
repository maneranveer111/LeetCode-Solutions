class Solution {
public:
    const int D = 31;
    const int Q = 1e9 + 9;
    
    string checkTrue(string& s, int len) {
        unordered_map<long long, int> mp;
        long long hPow = 1;
        for (int i = 0; i < len - 1; i++)
            hPow = (hPow * D) % Q;
        
        long long patHash = 0;
        for (int i = 0; i < len && i < s.size(); i++) {
            patHash = (D * patHash + s[i]) % Q;
        }
        
        mp[patHash] = 0;

        for(int i = 1; i + len <= s.size(); i++) {
            patHash = (D * (patHash - (long long)s[i - 1] * hPow) + s[i + len - 1]) % Q;
            if (patHash < 0) patHash += Q;

            if(mp.find(patHash) != mp.end()) {
                if(s.substr(mp[patHash], len) == s.substr(i, len))
                    return s.substr(i, len);
            } 

            mp[patHash] = i;
        }

        return "";
    }

    string longestDupSubstring(string s) {
        int lft = 1, rht = s.size() - 1;
        string ans = "";

        while(lft <= rht) {
            int mid = lft + (rht - lft) / 2;
            
            string temp = checkTrue(s, mid);
            if(temp.size() > 0) {
                lft = mid + 1;
                ans = temp;
            }
            else 
                rht = mid - 1;           
        }

        return ans;
    }
};