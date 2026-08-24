class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for(char ch : p)
            mp[ch]++;

        unordered_map<char, int> currmp;
        int lft = 0, dist = 0;
        vector<int> ans;

        for(int i = 0; i < s.size(); i++) {
            if(!mp.count(s[i])) {
                currmp.clear();
                lft = i + 1;
                dist = 0;
                continue;
            }

            if(currmp[s[i]] == 0) 
                dist++;
            currmp[s[i]]++;

            
            while(currmp[s[i]] > mp[s[i]]) {
                currmp[s[lft]]--;
                if(currmp[s[lft]] == 0)
                    dist--;
                lft++;
            }
            
            if(dist == mp.size() && (i - lft + 1) == p.size())
                ans.push_back(lft);
        }

        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

